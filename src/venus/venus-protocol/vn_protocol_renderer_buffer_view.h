/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_BUFFER_VIEW_H
#define VN_PROTOCOL_RENDERER_BUFFER_VIEW_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/* struct VkBufferViewCreateInfo chain */

static inline void *
vn_decode_VkBufferViewCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBufferViewCreateInfo_self_temp(struct vn_cs_decoder *dec, VkBufferViewCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkDeviceSize(dec, &val->offset);
    vn_decode_VkDeviceSize(dec, &val->range);
}

static inline void
vn_decode_VkBufferViewCreateInfo_temp(struct vn_cs_decoder *dec, VkBufferViewCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferViewCreateInfo_pnext_temp(dec);
    vn_decode_VkBufferViewCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkBufferViewCreateInfo_handle_self(VkBufferViewCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    vn_replace_VkBuffer_handle(&val->buffer);
    /* skip val->format */
    /* skip val->offset */
    /* skip val->range */
}

static inline void
vn_replace_VkBufferViewCreateInfo_handle(VkBufferViewCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            vn_replace_VkBufferViewCreateInfo_handle_self((VkBufferViewCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

static inline void vn_decode_vkCreateBufferView_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateBufferView *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkBufferViewCreateInfo_temp(dec, (VkBufferViewCreateInfo *)args->pCreateInfo);
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
        args->pView = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pView));
        if (!args->pView) return;
        vn_decode_VkBufferView(dec, args->pView);
    } else {
        args->pView = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkCreateBufferView_args_handle(struct vn_command_vkCreateBufferView *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkBufferViewCreateInfo_handle((VkBufferViewCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pView */
}

static inline void vn_encode_vkCreateBufferView_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateBufferView *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateBufferView_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pView))
        vn_encode_VkBufferView(enc, args->pView);
}

static inline void vn_decode_vkDestroyBufferView_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyBufferView *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkBufferView_lookup(dec, &args->bufferView);
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyBufferView_args_handle(struct vn_command_vkDestroyBufferView *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkBufferView_handle(&args->bufferView);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyBufferView_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyBufferView *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyBufferView_EXT});

    /* skip args->device */
    /* skip args->bufferView */
    /* skip args->pAllocator */
}

static inline void vn_dispatch_vkCreateBufferView(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateBufferView args;

    if (!ctx->dispatch_vkCreateBufferView) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateBufferView_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateBufferView(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkCreateBufferView returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateBufferView_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyBufferView(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyBufferView args;

    if (!ctx->dispatch_vkDestroyBufferView) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyBufferView_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyBufferView(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyBufferView_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_BUFFER_VIEW_H */
