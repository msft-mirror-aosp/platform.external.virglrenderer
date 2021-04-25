/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_SAMPLER_YCBCR_CONVERSION_H
#define VN_PROTOCOL_RENDERER_SAMPLER_YCBCR_CONVERSION_H

#include "vn_protocol_renderer_structs.h"

/* struct VkSamplerYcbcrConversionCreateInfo chain */

static inline void *
vn_decode_VkSamplerYcbcrConversionCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSamplerYcbcrConversionCreateInfo_self_temp(struct vn_cs_decoder *dec, VkSamplerYcbcrConversionCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkSamplerYcbcrModelConversion(dec, &val->ycbcrModel);
    vn_decode_VkSamplerYcbcrRange(dec, &val->ycbcrRange);
    vn_decode_VkComponentMapping_temp(dec, &val->components);
    vn_decode_VkChromaLocation(dec, &val->xChromaOffset);
    vn_decode_VkChromaLocation(dec, &val->yChromaOffset);
    vn_decode_VkFilter(dec, &val->chromaFilter);
    vn_decode_VkBool32(dec, &val->forceExplicitReconstruction);
}

static inline void
vn_decode_VkSamplerYcbcrConversionCreateInfo_temp(struct vn_cs_decoder *dec, VkSamplerYcbcrConversionCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerYcbcrConversionCreateInfo_pnext_temp(dec);
    vn_decode_VkSamplerYcbcrConversionCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkSamplerYcbcrConversionCreateInfo_handle_self(VkSamplerYcbcrConversionCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->format */
    /* skip val->ycbcrModel */
    /* skip val->ycbcrRange */
    vn_replace_VkComponentMapping_handle(&val->components);
    /* skip val->xChromaOffset */
    /* skip val->yChromaOffset */
    /* skip val->chromaFilter */
    /* skip val->forceExplicitReconstruction */
}

static inline void
vn_replace_VkSamplerYcbcrConversionCreateInfo_handle(VkSamplerYcbcrConversionCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            vn_replace_VkSamplerYcbcrConversionCreateInfo_handle_self((VkSamplerYcbcrConversionCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

static inline void vn_decode_vkCreateSamplerYcbcrConversion_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateSamplerYcbcrConversion *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkSamplerYcbcrConversionCreateInfo_temp(dec, (VkSamplerYcbcrConversionCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pYcbcrConversion = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pYcbcrConversion));
        if (!args->pYcbcrConversion) return;
        vn_decode_VkSamplerYcbcrConversion(dec, args->pYcbcrConversion);
    } else {
        args->pYcbcrConversion = NULL;
    }
}

static inline void vn_replace_vkCreateSamplerYcbcrConversion_args_handle(struct vn_command_vkCreateSamplerYcbcrConversion *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkSamplerYcbcrConversionCreateInfo_handle((VkSamplerYcbcrConversionCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pYcbcrConversion */
}

static inline void vn_encode_vkCreateSamplerYcbcrConversion_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateSamplerYcbcrConversion *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateSamplerYcbcrConversion_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pYcbcrConversion))
        vn_encode_VkSamplerYcbcrConversion(enc, args->pYcbcrConversion);
}

static inline void vn_decode_vkDestroySamplerYcbcrConversion_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroySamplerYcbcrConversion *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkSamplerYcbcrConversion_lookup(dec, &args->ycbcrConversion);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroySamplerYcbcrConversion_args_handle(struct vn_command_vkDestroySamplerYcbcrConversion *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkSamplerYcbcrConversion_handle(&args->ycbcrConversion);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroySamplerYcbcrConversion_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroySamplerYcbcrConversion *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroySamplerYcbcrConversion_EXT});

    /* skip args->device */
    /* skip args->ycbcrConversion */
    /* skip args->pAllocator */
}

static inline void vn_dispatch_vkCreateSamplerYcbcrConversion(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateSamplerYcbcrConversion args;

    if (!ctx->dispatch_vkCreateSamplerYcbcrConversion) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateSamplerYcbcrConversion_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateSamplerYcbcrConversion(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateSamplerYcbcrConversion returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateSamplerYcbcrConversion_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroySamplerYcbcrConversion(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroySamplerYcbcrConversion args;

    if (!ctx->dispatch_vkDestroySamplerYcbcrConversion) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroySamplerYcbcrConversion_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroySamplerYcbcrConversion(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroySamplerYcbcrConversion_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#endif /* VN_PROTOCOL_RENDERER_SAMPLER_YCBCR_CONVERSION_H */
