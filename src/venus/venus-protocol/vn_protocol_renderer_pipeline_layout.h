/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_PIPELINE_LAYOUT_H
#define VN_PROTOCOL_RENDERER_PIPELINE_LAYOUT_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ >= 12
#pragma GCC diagnostic ignored "-Wdangling-pointer"
#endif
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

static inline void vn_decode_vkCreatePipelineLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreatePipelineLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkPipelineLayoutCreateInfo_temp(dec, (VkPipelineLayoutCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pPipelineLayout = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPipelineLayout));
        if (!args->pPipelineLayout) return;
        vn_decode_VkPipelineLayout(dec, args->pPipelineLayout);
    } else {
        args->pPipelineLayout = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkCreatePipelineLayout_args_handle(struct vn_command_vkCreatePipelineLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkPipelineLayoutCreateInfo_handle((VkPipelineLayoutCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pPipelineLayout */
}

static inline void vn_encode_vkCreatePipelineLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreatePipelineLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreatePipelineLayout_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pPipelineLayout))
        vn_encode_VkPipelineLayout(enc, args->pPipelineLayout);
}

static inline void vn_decode_vkDestroyPipelineLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyPipelineLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkPipelineLayout_lookup(dec, &args->pipelineLayout);
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyPipelineLayout_args_handle(struct vn_command_vkDestroyPipelineLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkPipelineLayout_handle(&args->pipelineLayout);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyPipelineLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyPipelineLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyPipelineLayout_EXT});

    /* skip args->device */
    /* skip args->pipelineLayout */
    /* skip args->pAllocator */
}

static inline void vn_dispatch_vkCreatePipelineLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreatePipelineLayout args;

    if (!ctx->dispatch_vkCreatePipelineLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreatePipelineLayout_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreatePipelineLayout(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkCreatePipelineLayout returned %d", args.ret);
#endif

    if ((flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT) && !vn_cs_decoder_get_fatal(ctx->decoder)) {
        if (vn_cs_encoder_acquire(ctx->encoder)) {
            vn_encode_vkCreatePipelineLayout_reply(ctx->encoder, &args);
            vn_cs_encoder_release(ctx->encoder);
        }
    }

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyPipelineLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyPipelineLayout args;

    if (!ctx->dispatch_vkDestroyPipelineLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyPipelineLayout_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyPipelineLayout(ctx, &args);

    if ((flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT) && !vn_cs_decoder_get_fatal(ctx->decoder)) {
        if (vn_cs_encoder_acquire(ctx->encoder)) {
            vn_encode_vkDestroyPipelineLayout_reply(ctx->encoder, &args);
            vn_cs_encoder_release(ctx->encoder);
        }
    }

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_PIPELINE_LAYOUT_H */
