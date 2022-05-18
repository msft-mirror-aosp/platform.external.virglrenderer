#!/bin/sh

set -ex

if [ ${MESA_PROJECT_PATH} = "mesa/mesa" ]; then
    MESA_CI_PROJECT_DIR="/builds/${MESA_PROJECT_PATH}"
else
    # Hack to allow testing with a Mesa CI fork
    MESA_CI_PROJECT_DIR="/builds/mesa/mesa"

    # Sometimes LD_LIBRARY_PATH seem to be ignored by dEQP MESA-LOADER since
    # it still tries to load drivers from paths specific to Mesa container.
    export LIBGL_DRIVERS_PATH=${MESA_CI_PROJECT_DIR}/install/lib/dri
fi

mkdir -p ${MESA_CI_PROJECT_DIR}
cd ${MESA_CI_PROJECT_DIR}

# Deploy Mesa CI artifacts
MESA_CI_ARTIFACTS_URL="https://${MINIO_HOST}/artifacts/${MESA_PROJECT_PATH}/${MESA_PIPELINE_ID}/mesa-amd64.tar.gz"
if wget -q --method=HEAD ${MESA_CI_ARTIFACTS_URL}; then
    wget -S --progress=dot:giga -O- ${MESA_CI_ARTIFACTS_URL} | tar -xvz
else
    echo -e "\e[31mThe Mesa artifacts has expired, please update to newer Mesa pipeline!\e[0m"
    apt-get update && apt-get -y install jq
    FALLBACK_PAGE=1
    while :
    do
        MESA_JOB_ID=$(wget -cq "${CI_API_V4_URL}/projects/176/pipelines/${MESA_PIPELINE_ID}/jobs?per_page=100&page=${FALLBACK_PAGE}&scope=success" -O - \
          | jq -c '.[] | select(.name == "debian-testing") | .id')
        if [ ! -z "${MESA_JOB_ID}" ]; then
            break
        fi
        if [ $FALLBACK_PAGE -ge 10 ]; then
            echo -e "\e[31mUnable to find the debian-testing job!\e[0m"
            exit 1
        fi
        FALLBACK_PAGE=$((FALLBACK_PAGE+1))
    done
    MESA_CI_ARTIFACTS_URL="${CI_API_V4_URL}/projects/176/jobs/${MESA_JOB_ID}/artifacts/artifacts/install.tar"
    unset MESA_JOB_ID
    wget -S --progress=dot:giga -O- ${MESA_CI_ARTIFACTS_URL} | tar -xv
fi

# Overwrite Mesa CI's virglrenderer binaries with self built versions
cp -a ${CI_PROJECT_DIR}/install/bin/virgl_test_server /usr/local/bin/
cp -a ${CI_PROJECT_DIR}/install/lib/libvirglrenderer.so* /usr/local/lib/

if [ "${GALLIUM_DRIVER}" = "virgl" ]; then
    #
    # Run the tests on virtual platform (virgl/crosvm)
    #
    cp -a ${CI_PROJECT_DIR}/.gitlab-ci/expectations/virt/*.txt install/
    cp -a ${CI_PROJECT_DIR}/.gitlab-ci/expectations/virt/*.toml install/

    #
    # crosvm-runner.sh depends on resources from ${CI_PROJECT_DIR}/install,
    # but their actual location is ${MESA_CI_PROJECT_DIR}/install, hence
    # let's fix this using a bind mount.
    #
    mv ${CI_PROJECT_DIR}/install ${CI_PROJECT_DIR}/install-orig
    mkdir ${CI_PROJECT_DIR}/install
    mount --bind install ${CI_PROJECT_DIR}/install

    export LD_LIBRARY_PATH="${CI_PROJECT_DIR}/install/lib"
    set +e

    if [ -z "${DEQP_SUITE}" ]; then
        FDO_CI_CONCURRENT=${FORCE_FDO_CI_CONCURRENT:-FDO_CI_CONCURRENT} \
            install/crosvm-runner.sh install/piglit/piglit-runner.sh
    else
        install/deqp-runner.sh
    fi

    RET=$?

    # Cleanup
    umount ${CI_PROJECT_DIR}/install && \
    rmdir ${CI_PROJECT_DIR}/install && \
    mv ${CI_PROJECT_DIR}/install-orig ${CI_PROJECT_DIR}/install
else
    #
    # Run the tests on host platform (virpipe/vtest)
    #
    cp -a ${CI_PROJECT_DIR}/.gitlab-ci/expectations/host/*.txt install/
    cp -a ${CI_PROJECT_DIR}/.gitlab-ci/expectations/host/*.toml install/

    export LIBGL_ALWAYS_SOFTWARE="true"
    set +e

    if [ -z "${DEQP_SUITE}" ]; then
        PIGLIT_RUNNER_OPTIONS="--timeout 180" \
            install/piglit/piglit-runner.sh
    else
        DEQP_EXPECTED_RENDERER=virgl \
        WAFFLE_PLATFORM="surfaceless_egl" \
        SANITY_MESA_VERSION_CMD=wflinfo \
        HANG_DETECTION_CMD= \
        EGL_PLATFORM=surfaceless \
            install/deqp-runner.sh
    fi

    RET=$?
fi

mv -f results ${CI_PROJECT_DIR}/
exit ${RET}