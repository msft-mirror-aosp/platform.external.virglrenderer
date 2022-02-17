/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_TRANSPORT_H
#define VN_PROTOCOL_RENDERER_TRANSPORT_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/*
 * These structs/unions/commands are not included
 *
 *   vkGetMemoryFdKHR
 *   vkGetMemoryFdPropertiesKHR
 */

/* struct VkCommandStreamDescriptionMESA */

static inline void
vn_decode_VkCommandStreamDescriptionMESA_temp(struct vn_cs_decoder *dec, VkCommandStreamDescriptionMESA *val)
{
    vn_decode_uint32_t(dec, &val->resourceId);
    vn_decode_size_t(dec, &val->offset);
    vn_decode_size_t(dec, &val->size);
}

static inline void
vn_replace_VkCommandStreamDescriptionMESA_handle(VkCommandStreamDescriptionMESA *val)
{
    /* skip val->resourceId */
    /* skip val->offset */
    /* skip val->size */
}

/* struct VkCommandStreamDependencyMESA */

static inline void
vn_decode_VkCommandStreamDependencyMESA_temp(struct vn_cs_decoder *dec, VkCommandStreamDependencyMESA *val)
{
    vn_decode_uint32_t(dec, &val->srcCommandStream);
    vn_decode_uint32_t(dec, &val->dstCommandStream);
}

static inline void
vn_replace_VkCommandStreamDependencyMESA_handle(VkCommandStreamDependencyMESA *val)
{
    /* skip val->srcCommandStream */
    /* skip val->dstCommandStream */
}

/* struct VkRingCreateInfoMESA chain */

static inline void *
vn_decode_VkRingCreateInfoMESA_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkRingCreateInfoMESA_self_temp(struct vn_cs_decoder *dec, VkRingCreateInfoMESA *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->resourceId);
    vn_decode_size_t(dec, &val->offset);
    vn_decode_size_t(dec, &val->size);
    vn_decode_uint64_t(dec, &val->idleTimeout);
    vn_decode_size_t(dec, &val->headOffset);
    vn_decode_size_t(dec, &val->tailOffset);
    vn_decode_size_t(dec, &val->statusOffset);
    vn_decode_size_t(dec, &val->bufferOffset);
    vn_decode_size_t(dec, &val->bufferSize);
    vn_decode_size_t(dec, &val->extraOffset);
    vn_decode_size_t(dec, &val->extraSize);
}

static inline void
vn_decode_VkRingCreateInfoMESA_temp(struct vn_cs_decoder *dec, VkRingCreateInfoMESA *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_RING_CREATE_INFO_MESA)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkRingCreateInfoMESA_pnext_temp(dec);
    vn_decode_VkRingCreateInfoMESA_self_temp(dec, val);
}

static inline void
vn_replace_VkRingCreateInfoMESA_handle_self(VkRingCreateInfoMESA *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->resourceId */
    /* skip val->offset */
    /* skip val->size */
    /* skip val->idleTimeout */
    /* skip val->headOffset */
    /* skip val->tailOffset */
    /* skip val->statusOffset */
    /* skip val->bufferOffset */
    /* skip val->bufferSize */
    /* skip val->extraOffset */
    /* skip val->extraSize */
}

static inline void
vn_replace_VkRingCreateInfoMESA_handle(VkRingCreateInfoMESA *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_RING_CREATE_INFO_MESA:
            vn_replace_VkRingCreateInfoMESA_handle_self((VkRingCreateInfoMESA *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkMemoryResourceAllocationSizeProperties100000MESA chain */

static inline void
vn_encode_VkMemoryResourceAllocationSizeProperties100000MESA_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkMemoryResourceAllocationSizeProperties100000MESA_self(struct vn_cs_encoder *enc, const VkMemoryResourceAllocationSizeProperties100000MESA *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint64_t(enc, &val->allocationSize);
}

static inline void
vn_encode_VkMemoryResourceAllocationSizeProperties100000MESA(struct vn_cs_encoder *enc, const VkMemoryResourceAllocationSizeProperties100000MESA *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_MEMORY_RESOURCE_ALLOCATION_SIZE_PROPERTIES_100000_MESA);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_MEMORY_RESOURCE_ALLOCATION_SIZE_PROPERTIES_100000_MESA });
    vn_encode_VkMemoryResourceAllocationSizeProperties100000MESA_pnext(enc, val->pNext);
    vn_encode_VkMemoryResourceAllocationSizeProperties100000MESA_self(enc, val);
}

static inline void *
vn_decode_VkMemoryResourceAllocationSizeProperties100000MESA_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkMemoryResourceAllocationSizeProperties100000MESA_self_partial_temp(struct vn_cs_decoder *dec, VkMemoryResourceAllocationSizeProperties100000MESA *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->allocationSize */
}

static inline void
vn_decode_VkMemoryResourceAllocationSizeProperties100000MESA_partial_temp(struct vn_cs_decoder *dec, VkMemoryResourceAllocationSizeProperties100000MESA *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_MEMORY_RESOURCE_ALLOCATION_SIZE_PROPERTIES_100000_MESA)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryResourceAllocationSizeProperties100000MESA_pnext_partial_temp(dec);
    vn_decode_VkMemoryResourceAllocationSizeProperties100000MESA_self_partial_temp(dec, val);
}

/* struct VkMemoryResourcePropertiesMESA chain */

static inline void
vn_encode_VkMemoryResourcePropertiesMESA_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MEMORY_RESOURCE_ALLOCATION_SIZE_PROPERTIES_100000_MESA:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkMemoryResourcePropertiesMESA_pnext(enc, pnext->pNext);
            vn_encode_VkMemoryResourceAllocationSizeProperties100000MESA_self(enc, (const VkMemoryResourceAllocationSizeProperties100000MESA *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkMemoryResourcePropertiesMESA_self(struct vn_cs_encoder *enc, const VkMemoryResourcePropertiesMESA *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->memoryTypeBits);
}

static inline void
vn_encode_VkMemoryResourcePropertiesMESA(struct vn_cs_encoder *enc, const VkMemoryResourcePropertiesMESA *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_MEMORY_RESOURCE_PROPERTIES_MESA);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_MEMORY_RESOURCE_PROPERTIES_MESA });
    vn_encode_VkMemoryResourcePropertiesMESA_pnext(enc, val->pNext);
    vn_encode_VkMemoryResourcePropertiesMESA_self(enc, val);
}

static inline void *
vn_decode_VkMemoryResourcePropertiesMESA_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_MEMORY_RESOURCE_ALLOCATION_SIZE_PROPERTIES_100000_MESA:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkMemoryResourceAllocationSizeProperties100000MESA));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryResourcePropertiesMESA_pnext_partial_temp(dec);
            vn_decode_VkMemoryResourceAllocationSizeProperties100000MESA_self_partial_temp(dec, (VkMemoryResourceAllocationSizeProperties100000MESA *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkMemoryResourcePropertiesMESA_self_partial_temp(struct vn_cs_decoder *dec, VkMemoryResourcePropertiesMESA *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->memoryTypeBits */
}

static inline void
vn_decode_VkMemoryResourcePropertiesMESA_partial_temp(struct vn_cs_decoder *dec, VkMemoryResourcePropertiesMESA *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_MEMORY_RESOURCE_PROPERTIES_MESA)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryResourcePropertiesMESA_pnext_partial_temp(dec);
    vn_decode_VkMemoryResourcePropertiesMESA_self_partial_temp(dec, val);
}

static inline void vn_decode_vkSetReplyCommandStreamMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkSetReplyCommandStreamMESA *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pStream = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pStream));
        if (!args->pStream) return;
        vn_decode_VkCommandStreamDescriptionMESA_temp(dec, (VkCommandStreamDescriptionMESA *)args->pStream);
    } else {
        args->pStream = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkSetReplyCommandStreamMESA_args_handle(struct vn_command_vkSetReplyCommandStreamMESA *args)
{
    if (args->pStream)
        vn_replace_VkCommandStreamDescriptionMESA_handle((VkCommandStreamDescriptionMESA *)args->pStream);
}

static inline void vn_encode_vkSetReplyCommandStreamMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkSetReplyCommandStreamMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkSetReplyCommandStreamMESA_EXT});

    /* skip args->pStream */
}

static inline void vn_decode_vkSeekReplyCommandStreamMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkSeekReplyCommandStreamMESA *args)
{
    vn_decode_size_t(dec, &args->position);
}

static inline void vn_replace_vkSeekReplyCommandStreamMESA_args_handle(struct vn_command_vkSeekReplyCommandStreamMESA *args)
{
    /* skip args->position */
}

static inline void vn_encode_vkSeekReplyCommandStreamMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkSeekReplyCommandStreamMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkSeekReplyCommandStreamMESA_EXT});

    /* skip args->position */
}

static inline void vn_decode_vkExecuteCommandStreamsMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkExecuteCommandStreamsMESA *args)
{
    vn_decode_uint32_t(dec, &args->streamCount);
    if (vn_peek_array_size(dec)) {
        const uint32_t iter_count = vn_decode_array_size(dec, args->streamCount);
        args->pStreams = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pStreams) * iter_count);
        if (!args->pStreams) return;
        for (uint32_t i = 0; i < iter_count; i++)
            vn_decode_VkCommandStreamDescriptionMESA_temp(dec, &((VkCommandStreamDescriptionMESA *)args->pStreams)[i]);
    } else {
        vn_decode_array_size(dec, args->streamCount);
        args->pStreams = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->streamCount);
        args->pReplyPositions = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pReplyPositions) * array_size);
        if (!args->pReplyPositions) return;
        vn_decode_size_t_array(dec, (size_t *)args->pReplyPositions, array_size);
    } else {
        vn_decode_array_size_unchecked(dec);
        args->pReplyPositions = NULL;
    }
    vn_decode_uint32_t(dec, &args->dependencyCount);
    if (vn_peek_array_size(dec)) {
        const uint32_t iter_count = vn_decode_array_size(dec, args->dependencyCount);
        args->pDependencies = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDependencies) * iter_count);
        if (!args->pDependencies) return;
        for (uint32_t i = 0; i < iter_count; i++)
            vn_decode_VkCommandStreamDependencyMESA_temp(dec, &((VkCommandStreamDependencyMESA *)args->pDependencies)[i]);
    } else {
        vn_decode_array_size(dec, args->dependencyCount);
        args->pDependencies = NULL;
    }
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkExecuteCommandStreamsMESA_args_handle(struct vn_command_vkExecuteCommandStreamsMESA *args)
{
    /* skip args->streamCount */
    if (args->pStreams) {
       for (uint32_t i = 0; i < args->streamCount; i++)
            vn_replace_VkCommandStreamDescriptionMESA_handle(&((VkCommandStreamDescriptionMESA *)args->pStreams)[i]);
    }
    /* skip args->pReplyPositions */
    /* skip args->dependencyCount */
    if (args->pDependencies) {
       for (uint32_t i = 0; i < args->dependencyCount; i++)
            vn_replace_VkCommandStreamDependencyMESA_handle(&((VkCommandStreamDependencyMESA *)args->pDependencies)[i]);
    }
    /* skip args->flags */
}

static inline void vn_encode_vkExecuteCommandStreamsMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkExecuteCommandStreamsMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkExecuteCommandStreamsMESA_EXT});

    /* skip args->streamCount */
    /* skip args->pStreams */
    /* skip args->pReplyPositions */
    /* skip args->dependencyCount */
    /* skip args->pDependencies */
    /* skip args->flags */
}

static inline void vn_decode_vkCreateRingMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateRingMESA *args)
{
    vn_decode_uint64_t(dec, &args->ring);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkRingCreateInfoMESA_temp(dec, (VkRingCreateInfoMESA *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkCreateRingMESA_args_handle(struct vn_command_vkCreateRingMESA *args)
{
    /* skip args->ring */
    if (args->pCreateInfo)
        vn_replace_VkRingCreateInfoMESA_handle((VkRingCreateInfoMESA *)args->pCreateInfo);
}

static inline void vn_encode_vkCreateRingMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateRingMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateRingMESA_EXT});

    /* skip args->ring */
    /* skip args->pCreateInfo */
}

static inline void vn_decode_vkDestroyRingMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyRingMESA *args)
{
    vn_decode_uint64_t(dec, &args->ring);
}

static inline void vn_replace_vkDestroyRingMESA_args_handle(struct vn_command_vkDestroyRingMESA *args)
{
    /* skip args->ring */
}

static inline void vn_encode_vkDestroyRingMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyRingMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyRingMESA_EXT});

    /* skip args->ring */
}

static inline void vn_decode_vkNotifyRingMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkNotifyRingMESA *args)
{
    vn_decode_uint64_t(dec, &args->ring);
    vn_decode_uint32_t(dec, &args->seqno);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkNotifyRingMESA_args_handle(struct vn_command_vkNotifyRingMESA *args)
{
    /* skip args->ring */
    /* skip args->seqno */
    /* skip args->flags */
}

static inline void vn_encode_vkNotifyRingMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkNotifyRingMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkNotifyRingMESA_EXT});

    /* skip args->ring */
    /* skip args->seqno */
    /* skip args->flags */
}

static inline void vn_decode_vkWriteRingExtraMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkWriteRingExtraMESA *args)
{
    vn_decode_uint64_t(dec, &args->ring);
    vn_decode_size_t(dec, &args->offset);
    vn_decode_uint32_t(dec, &args->value);
}

static inline void vn_replace_vkWriteRingExtraMESA_args_handle(struct vn_command_vkWriteRingExtraMESA *args)
{
    /* skip args->ring */
    /* skip args->offset */
    /* skip args->value */
}

static inline void vn_encode_vkWriteRingExtraMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkWriteRingExtraMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkWriteRingExtraMESA_EXT});

    /* skip args->ring */
    /* skip args->offset */
    /* skip args->value */
}

static inline void vn_decode_vkGetMemoryResourcePropertiesMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetMemoryResourcePropertiesMESA *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->resourceId);
    if (vn_decode_simple_pointer(dec)) {
        args->pMemoryResourceProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryResourceProperties));
        if (!args->pMemoryResourceProperties) return;
        vn_decode_VkMemoryResourcePropertiesMESA_partial_temp(dec, args->pMemoryResourceProperties);
    } else {
        args->pMemoryResourceProperties = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkGetMemoryResourcePropertiesMESA_args_handle(struct vn_command_vkGetMemoryResourcePropertiesMESA *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->resourceId */
    /* skip args->pMemoryResourceProperties */
}

static inline void vn_encode_vkGetMemoryResourcePropertiesMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetMemoryResourcePropertiesMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetMemoryResourcePropertiesMESA_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->resourceId */
    if (vn_encode_simple_pointer(enc, args->pMemoryResourceProperties))
        vn_encode_VkMemoryResourcePropertiesMESA(enc, args->pMemoryResourceProperties);
}

static inline void vn_decode_vkGetVenusExperimentalFeatureData100000MESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetVenusExperimentalFeatureData100000MESA *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pDataSize = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDataSize));
        if (!args->pDataSize) return;
        vn_decode_size_t(dec, args->pDataSize);
    } else {
        args->pDataSize = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, (args->pDataSize ? *args->pDataSize : 0));
        args->pData = vn_cs_decoder_alloc_temp(dec, array_size);
        if (!args->pData) return;
    } else {
        vn_decode_array_size_unchecked(dec);
        args->pData = NULL;
    }
}

static inline void vn_replace_vkGetVenusExperimentalFeatureData100000MESA_args_handle(struct vn_command_vkGetVenusExperimentalFeatureData100000MESA *args)
{
    /* skip args->pDataSize */
    /* skip args->pData */
}

static inline void vn_encode_vkGetVenusExperimentalFeatureData100000MESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetVenusExperimentalFeatureData100000MESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetVenusExperimentalFeatureData100000MESA_EXT});

    if (vn_encode_simple_pointer(enc, args->pDataSize))
        vn_encode_size_t(enc, args->pDataSize);
    if (args->pData) {
        vn_encode_array_size(enc, (args->pDataSize ? *args->pDataSize : 0));
        vn_encode_blob_array(enc, args->pData, (args->pDataSize ? *args->pDataSize : 0));
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_dispatch_vkSetReplyCommandStreamMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkSetReplyCommandStreamMESA args;

    if (!ctx->dispatch_vkSetReplyCommandStreamMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkSetReplyCommandStreamMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkSetReplyCommandStreamMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkSetReplyCommandStreamMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkSeekReplyCommandStreamMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkSeekReplyCommandStreamMESA args;

    if (!ctx->dispatch_vkSeekReplyCommandStreamMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkSeekReplyCommandStreamMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkSeekReplyCommandStreamMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkSeekReplyCommandStreamMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkExecuteCommandStreamsMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkExecuteCommandStreamsMESA args;

    if (!ctx->dispatch_vkExecuteCommandStreamsMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkExecuteCommandStreamsMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkExecuteCommandStreamsMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkExecuteCommandStreamsMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateRingMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateRingMESA args;

    if (!ctx->dispatch_vkCreateRingMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateRingMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateRingMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateRingMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyRingMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyRingMESA args;

    if (!ctx->dispatch_vkDestroyRingMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyRingMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyRingMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyRingMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkNotifyRingMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkNotifyRingMESA args;

    if (!ctx->dispatch_vkNotifyRingMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkNotifyRingMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkNotifyRingMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkNotifyRingMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkWriteRingExtraMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkWriteRingExtraMESA args;

    if (!ctx->dispatch_vkWriteRingExtraMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkWriteRingExtraMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkWriteRingExtraMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkWriteRingExtraMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetMemoryResourcePropertiesMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetMemoryResourcePropertiesMESA args;

    if (!ctx->dispatch_vkGetMemoryResourcePropertiesMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetMemoryResourcePropertiesMESA_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetMemoryResourcePropertiesMESA(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkGetMemoryResourcePropertiesMESA returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetMemoryResourcePropertiesMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetVenusExperimentalFeatureData100000MESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetVenusExperimentalFeatureData100000MESA args;

    if (!ctx->dispatch_vkGetVenusExperimentalFeatureData100000MESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetVenusExperimentalFeatureData100000MESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetVenusExperimentalFeatureData100000MESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetVenusExperimentalFeatureData100000MESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_TRANSPORT_H */
