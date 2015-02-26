/**************************************************************************
 *
 * Copyright (C) 2014 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

/* helper functions for testing purposes */
#include <check.h>
#include <errno.h>
#include <sys/uio.h>
#include "pipe/p_defines.h"
#include "pipe/p_format.h"
#include "util/u_memory.h"
#include "util/u_format.h"
#include "testvirgl.h"

#include "virglrenderer.h"

void testvirgl_init_simple_1d_resource(struct virgl_renderer_resource_create_args *res, int handle)
{
    res->handle = handle;
    res->target = PIPE_TEXTURE_1D;
    res->format = PIPE_FORMAT_B8G8R8X8_UNORM;
    res->width = 50;
    res->height = 1;
    res->depth = 1;
    res->array_size = 1;
    res->last_level = 0;
    res->nr_samples = 0;
    res->bind = PIPE_BIND_SAMPLER_VIEW;
    res->flags = 0;
}

void testvirgl_init_simple_buffer(struct virgl_renderer_resource_create_args *res, int handle)
{
    res->handle = handle;
    res->target = PIPE_BUFFER;
    res->format = PIPE_FORMAT_R8_UNORM;
    res->width = 50;
    res->height = 1;
    res->depth = 1;
    res->array_size = 1;
    res->last_level = 0;
    res->nr_samples = 0;
    res->bind = 0;
    res->flags = 0;
}

void testvirgl_init_simple_2d_resource(struct virgl_renderer_resource_create_args *res, int handle)
{
    res->handle = handle;
    res->target = PIPE_TEXTURE_2D;
    res->format = PIPE_FORMAT_B8G8R8X8_UNORM;
    res->width = 50;
    res->height = 50;
    res->depth = 1;
    res->array_size = 1;
    res->last_level = 0;
    res->nr_samples = 0;
    res->bind = PIPE_BIND_SAMPLER_VIEW;
    res->flags = 0;
}


struct myinfo_struct {
  uint32_t test;
};

static struct myinfo_struct mystruct;

static struct virgl_renderer_callbacks test_cbs;

int testvirgl_init_single_ctx(void)
{
    int ret;

    test_cbs.version = 1;
    ret = virgl_renderer_init(&mystruct, VIRGL_RENDERER_USE_EGL, &test_cbs);
    ck_assert_int_eq(ret, 0);
    if (ret)
	return ret;
    ret = virgl_renderer_context_create(1, strlen("test1"), "test1");
    ck_assert_int_eq(ret, 0);
    return ret;

}

void testvirgl_init_single_ctx_nr(void)
{
    testvirgl_init_single_ctx();
}

void testvirgl_fini_single_ctx(void)
{
    virgl_renderer_context_destroy(1);
    virgl_renderer_cleanup(&mystruct);
}

int testvirgl_init_ctx_cmdbuf(struct virgl_context *ctx)
{
    int ret;
    ret = testvirgl_init_single_ctx();
    if (ret)
	return ret;

    ctx->ctx_id = 1;
    ctx->cbuf = CALLOC_STRUCT(virgl_cmd_buf);
    if (!ctx->cbuf) {
	testvirgl_fini_single_ctx();
	return ENOMEM;
    }

    ctx->cbuf->buf = CALLOC(1, VIRGL_MAX_CMDBUF_DWORDS);
    if (!ctx->cbuf->buf) {
	FREE(ctx->cbuf);
	testvirgl_fini_single_ctx();
	return ENOMEM;
    }
    return 0;
}

void testvirgl_fini_ctx_cmdbuf(struct virgl_context *ctx)
{
    FREE(ctx->cbuf->buf);
    FREE(ctx->cbuf);
    testvirgl_fini_single_ctx();
}

int testvirgl_create_backed_simple_2d_res(struct virgl_resource *res,
					  int handle)
{
    struct virgl_renderer_resource_create_args args;
    uint32_t backing_size;
    int ret;

    testvirgl_init_simple_2d_resource(&args, handle);
    ret = virgl_renderer_resource_create(&args, NULL, 0);
    ck_assert_int_eq(ret, 0);

    res->handle = handle;
    res->base.target = args.target;
    res->base.format = args.format;

    backing_size = args.width * args.height * util_format_get_blocksize(res->base.format);
    res->iovs = malloc(sizeof(struct iovec));

    res->iovs[0].iov_base = malloc(backing_size);
    res->iovs[0].iov_len = backing_size;
    res->niovs = 1;

    virgl_renderer_resource_attach_iov(res->handle, res->iovs, res->niovs);
    return 0;
}

void testvirgl_destroy_backed_res(struct virgl_resource *res)
{
    struct iovec *iovs;
    int niovs;

    virgl_renderer_resource_detach_iov(res->handle, &iovs, &niovs);

    free(iovs[0].iov_base);
    free(iovs);
    virgl_renderer_resource_unref(res->handle);
}
