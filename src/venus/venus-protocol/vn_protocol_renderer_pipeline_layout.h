/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_PIPELINE_LAYOUT_H
#define VN_PROTOCOL_RENDERER_PIPELINE_LAYOUT_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/* struct VkPushConstantRange */

static inline void
vn_decode_VkPushConstantRange_temp(struct vn_cs_decoder *dec, VkPushConstantRange *val)
{
    vn_decode_VkFlags(dec, &val->stageFlags);
    vn_decode_uint32_t(dec, &val->offset);
    vn_decode_uint32_t(dec, &val->size);
}

static inline void
vn_replace_VkPushConstantRange_handle(VkPushConstantRange *val)
{
    /* skip val->stageFlags */
    /* skip val->offset */
    /* skip val->size */
}

/* struct VkPipelineLayoutCreateInfo chain */

static inline void *
vn_decode_VkPipelineLayoutCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineLayoutCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineLayoutCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->setLayoutCount);
    if (vn_peek_array_size(dec)) {
        const uint32_t iter_count = vn_decode_array_size(dec, val->setLayoutCount);
        val->pSetLayouts = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSetLayouts) * iter_count);
        if (!val->pSetLayouts) return;
        for (uint32_t i = 0; i < iter_count; i++)
            vn_decode_VkDescriptorSetLayout_lookup(dec, &((VkDescriptorSetLayout *)val->pSetLayouts)[i]);
    } else {
        vn_decode_array_size(dec, val->setLayoutCount);
        val->pSetLayouts = NULL;
    }
    vn_decode_uint32_t(dec, &val->pushConstantRangeCount);
    if (vn_peek_array_size(dec)) {
        const uint32_t iter_count = vn_decode_array_size(dec, val->pushConstantRangeCount);
        val->pPushConstantRanges = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pPushConstantRanges) * iter_count);
        if (!val->pPushConstantRanges) return;
        for (uint32_t i = 0; i < iter_count; i++)
            vn_decode_VkPushConstantRange_temp(dec, &((VkPushConstantRange *)val->pPushConstantRanges)[i]);
    } else {
        vn_decode_array_size(dec, val->pushConstantRangeCount);
        val->pPushConstantRanges = NULL;
    }
}

static inline void
vn_decode_VkPipelineLayoutCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineLayoutCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineLayoutCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineLayoutCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkPipelineLayoutCreateInfo_handle_self(VkPipelineLayoutCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->setLayoutCount */
    if (val->pSetLayouts) {
       for (uint32_t i = 0; i < val->setLayoutCount; i++)
            vn_replace_VkDescriptorSetLayout_handle(&((VkDescriptorSetLayout *)val->pSetLayouts)[i]);
    }
    /* skip val->pushConstantRangeCount */
    if (val->pPushConstantRanges) {
       for (uint32_t i = 0; i < val->pushConstantRangeCount; i++)
            vn_replace_VkPushConstantRange_handle(&((VkPushConstantRange *)val->pPushConstantRanges)[i]);
    }
}

static inline void
vn_replace_VkPipelineLayoutCreateInfo_handle(VkPipelineLayoutCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            vn_replace_VkPipelineLayoutCreateInfo_handle_self((VkPipelineLayoutCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

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

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreatePipelineLayout_reply(ctx->encoder, &args);

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


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyPipelineLayout_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_PIPELINE_LAYOUT_H */
