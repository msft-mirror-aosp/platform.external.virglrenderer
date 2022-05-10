/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_DESCRIPTOR_POOL_H
#define VN_PROTOCOL_RENDERER_DESCRIPTOR_POOL_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/* struct VkDescriptorPoolSize */

static inline void
vn_decode_VkDescriptorPoolSize_temp(struct vn_cs_decoder *dec, VkDescriptorPoolSize *val)
{
    vn_decode_VkDescriptorType(dec, &val->type);
    vn_decode_uint32_t(dec, &val->descriptorCount);
}

static inline void
vn_replace_VkDescriptorPoolSize_handle(VkDescriptorPoolSize *val)
{
    /* skip val->type */
    /* skip val->descriptorCount */
}

/* struct VkDescriptorPoolCreateInfo chain */

static inline void *
vn_decode_VkDescriptorPoolCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDescriptorPoolCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorPoolCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->maxSets);
    vn_decode_uint32_t(dec, &val->poolSizeCount);
    if (vn_peek_array_size(dec)) {
        const uint32_t iter_count = vn_decode_array_size(dec, val->poolSizeCount);
        val->pPoolSizes = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pPoolSizes) * iter_count);
        if (!val->pPoolSizes) return;
        for (uint32_t i = 0; i < iter_count; i++)
            vn_decode_VkDescriptorPoolSize_temp(dec, &((VkDescriptorPoolSize *)val->pPoolSizes)[i]);
    } else {
        vn_decode_array_size(dec, val->poolSizeCount);
        val->pPoolSizes = NULL;
    }
}

static inline void
vn_decode_VkDescriptorPoolCreateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorPoolCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorPoolCreateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorPoolCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkDescriptorPoolCreateInfo_handle_self(VkDescriptorPoolCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->maxSets */
    /* skip val->poolSizeCount */
    if (val->pPoolSizes) {
       for (uint32_t i = 0; i < val->poolSizeCount; i++)
            vn_replace_VkDescriptorPoolSize_handle(&((VkDescriptorPoolSize *)val->pPoolSizes)[i]);
    }
}

static inline void
vn_replace_VkDescriptorPoolCreateInfo_handle(VkDescriptorPoolCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            vn_replace_VkDescriptorPoolCreateInfo_handle_self((VkDescriptorPoolCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

static inline void vn_decode_vkCreateDescriptorPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateDescriptorPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkDescriptorPoolCreateInfo_temp(dec, (VkDescriptorPoolCreateInfo *)args->pCreateInfo);
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
        args->pDescriptorPool = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDescriptorPool));
        if (!args->pDescriptorPool) return;
        vn_decode_VkDescriptorPool(dec, args->pDescriptorPool);
    } else {
        args->pDescriptorPool = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkCreateDescriptorPool_args_handle(struct vn_command_vkCreateDescriptorPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkDescriptorPoolCreateInfo_handle((VkDescriptorPoolCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pDescriptorPool */
}

static inline void vn_encode_vkCreateDescriptorPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateDescriptorPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateDescriptorPool_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pDescriptorPool))
        vn_encode_VkDescriptorPool(enc, args->pDescriptorPool);
}

static inline void vn_decode_vkDestroyDescriptorPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyDescriptorPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDescriptorPool_lookup(dec, &args->descriptorPool);
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyDescriptorPool_args_handle(struct vn_command_vkDestroyDescriptorPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDescriptorPool_handle(&args->descriptorPool);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyDescriptorPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyDescriptorPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyDescriptorPool_EXT});

    /* skip args->device */
    /* skip args->descriptorPool */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkResetDescriptorPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetDescriptorPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDescriptorPool_lookup(dec, &args->descriptorPool);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkResetDescriptorPool_args_handle(struct vn_command_vkResetDescriptorPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDescriptorPool_handle(&args->descriptorPool);
    /* skip args->flags */
}

static inline void vn_encode_vkResetDescriptorPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetDescriptorPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetDescriptorPool_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->descriptorPool */
    /* skip args->flags */
}

static inline void vn_dispatch_vkCreateDescriptorPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateDescriptorPool args;

    if (!ctx->dispatch_vkCreateDescriptorPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateDescriptorPool_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateDescriptorPool(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkCreateDescriptorPool returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateDescriptorPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyDescriptorPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyDescriptorPool args;

    if (!ctx->dispatch_vkDestroyDescriptorPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyDescriptorPool_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyDescriptorPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyDescriptorPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetDescriptorPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetDescriptorPool args;

    if (!ctx->dispatch_vkResetDescriptorPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetDescriptorPool_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetDescriptorPool(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkResetDescriptorPool returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetDescriptorPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_DESCRIPTOR_POOL_H */
