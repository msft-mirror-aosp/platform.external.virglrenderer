/**************************************************************************
 * 
 * Copyright 2007 VMware, Inc.
 * Copyright (c) 2008 VMware, Inc.
 * All Rights Reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 **************************************************************************/

#ifndef PIPE_FORMAT_H
#define PIPE_FORMAT_H

#include "p_config.h"
#include "virgl_hw.h"

#ifdef __cplusplus
extern "C" {
#endif


#define pipe_format virgl_formats
/**
 * Formats for textures, surfaces and vertex data
 */
#define PIPE_FORMAT_NONE           VIRGL_FORMAT_NONE
#define PIPE_FORMAT_B8G8R8A8_UNORM VIRGL_FORMAT_B8G8R8A8_UNORM
#define PIPE_FORMAT_B8G8R8X8_UNORM VIRGL_FORMAT_B8G8R8X8_UNORM
#define PIPE_FORMAT_A8R8G8B8_UNORM VIRGL_FORMAT_A8R8G8B8_UNORM
#define PIPE_FORMAT_X8R8G8B8_UNORM VIRGL_FORMAT_X8R8G8B8_UNORM
#define PIPE_FORMAT_B5G5R5A1_UNORM VIRGL_FORMAT_B5G5R5A1_UNORM
#define PIPE_FORMAT_B4G4R4A4_UNORM VIRGL_FORMAT_B4G4R4A4_UNORM
#define PIPE_FORMAT_B5G6R5_UNORM VIRGL_FORMAT_B5G6R5_UNORM
#define PIPE_FORMAT_R10G10B10A2_UNORM VIRGL_FORMAT_R10G10B10A2_UNORM
#define PIPE_FORMAT_L8_UNORM VIRGL_FORMAT_L8_UNORM                    /**< ubyte luminance */
#define PIPE_FORMAT_A8_UNORM VIRGL_FORMAT_A8_UNORM                   /**< ubyte alpha */
#define PIPE_FORMAT_I8_UNORM VIRGL_FORMAT_I8_UNORM                   /**< ubyte intensity */
#define PIPE_FORMAT_L8A8_UNORM VIRGL_FORMAT_L8A8_UNORM                 /**< ubyte alpha, luminance */
#define PIPE_FORMAT_L16_UNORM VIRGL_FORMAT_L16_UNORM                  /**< ushort luminance */
#define PIPE_FORMAT_UYVY VIRGL_FORMAT_UYVY
#define PIPE_FORMAT_YUYV VIRGL_FORMAT_YUYV
#define PIPE_FORMAT_Z16_UNORM VIRGL_FORMAT_Z16_UNORM
#define PIPE_FORMAT_Z32_UNORM VIRGL_FORMAT_Z32_UNORM
#define PIPE_FORMAT_Z32_FLOAT VIRGL_FORMAT_Z32_FLOAT
#define PIPE_FORMAT_Z24_UNORM_S8_UINT VIRGL_FORMAT_Z24_UNORM_S8_UINT
#define PIPE_FORMAT_S8_UINT_Z24_UNORM VIRGL_FORMAT_S8_UINT_Z24_UNORM
#define PIPE_FORMAT_Z24X8_UNORM VIRGL_FORMAT_Z24X8_UNORM
#define PIPE_FORMAT_X8Z24_UNORM VIRGL_FORMAT_X8Z24_UNORM
#define PIPE_FORMAT_S8_UINT VIRGL_FORMAT_S8_UINT                    /**< ubyte stencil */
#define PIPE_FORMAT_R64_FLOAT VIRGL_FORMAT_R64_FLOAT
#define PIPE_FORMAT_R64G64_FLOAT VIRGL_FORMAT_R64G64_FLOAT
#define PIPE_FORMAT_R64G64B64_FLOAT VIRGL_FORMAT_R64G64B64_FLOAT
#define PIPE_FORMAT_R64G64B64A64_FLOAT VIRGL_FORMAT_R64G64B64A64_FLOAT
#define PIPE_FORMAT_R32_FLOAT VIRGL_FORMAT_R32_FLOAT
#define PIPE_FORMAT_R32G32_FLOAT VIRGL_FORMAT_R32G32_FLOAT
#define PIPE_FORMAT_R32G32B32_FLOAT VIRGL_FORMAT_R32G32B32_FLOAT
#define PIPE_FORMAT_R32G32B32A32_FLOAT VIRGL_FORMAT_R32G32B32A32_FLOAT
#define PIPE_FORMAT_R32_UNORM VIRGL_FORMAT_R32_UNORM
#define PIPE_FORMAT_R32G32_UNORM VIRGL_FORMAT_R32G32_UNORM
#define PIPE_FORMAT_R32G32B32_UNORM VIRGL_FORMAT_R32G32B32_UNORM
#define PIPE_FORMAT_R32G32B32A32_UNORM VIRGL_FORMAT_R32G32B32A32_UNORM
#define PIPE_FORMAT_R32_USCALED VIRGL_FORMAT_R32_USCALED
#define PIPE_FORMAT_R32G32_USCALED VIRGL_FORMAT_R32G32_USCALED
#define PIPE_FORMAT_R32G32B32_USCALED VIRGL_FORMAT_R32G32B32_USCALED
#define PIPE_FORMAT_R32G32B32A32_USCALED VIRGL_FORMAT_R32G32B32A32_USCALED
#define PIPE_FORMAT_R32_SNORM VIRGL_FORMAT_R32_SNORM
#define PIPE_FORMAT_R32G32_SNORM VIRGL_FORMAT_R32G32_SNORM
#define PIPE_FORMAT_R32G32B32_SNORM VIRGL_FORMAT_R32G32B32_SNORM
#define PIPE_FORMAT_R32G32B32A32_SNORM VIRGL_FORMAT_R32G32B32A32_SNORM
#define PIPE_FORMAT_R32_SSCALED VIRGL_FORMAT_R32_SSCALED
#define PIPE_FORMAT_R32G32_SSCALED VIRGL_FORMAT_R32G32_SSCALED
#define PIPE_FORMAT_R32G32B32_SSCALED VIRGL_FORMAT_R32G32B32_SSCALED
#define PIPE_FORMAT_R32G32B32A32_SSCALED VIRGL_FORMAT_R32G32B32A32_SSCALED
#define PIPE_FORMAT_R16_UNORM VIRGL_FORMAT_R16_UNORM
#define PIPE_FORMAT_R16G16_UNORM VIRGL_FORMAT_R16G16_UNORM
#define PIPE_FORMAT_R16G16B16_UNORM VIRGL_FORMAT_R16G16B16_UNORM
#define PIPE_FORMAT_R16G16B16A16_UNORM VIRGL_FORMAT_R16G16B16A16_UNORM
#define PIPE_FORMAT_R16_USCALED VIRGL_FORMAT_R16_USCALED
#define PIPE_FORMAT_R16G16_USCALED VIRGL_FORMAT_R16G16_USCALED
#define PIPE_FORMAT_R16G16B16_USCALED VIRGL_FORMAT_R16G16B16_USCALED
#define PIPE_FORMAT_R16G16B16A16_USCALED VIRGL_FORMAT_R16G16B16A16_USCALED
#define PIPE_FORMAT_R16_SNORM VIRGL_FORMAT_R16_SNORM
#define PIPE_FORMAT_R16G16_SNORM VIRGL_FORMAT_R16G16_SNORM
#define PIPE_FORMAT_R16G16B16_SNORM VIRGL_FORMAT_R16G16B16_SNORM
#define PIPE_FORMAT_R16G16B16A16_SNORM VIRGL_FORMAT_R16G16B16A16_SNORM
#define PIPE_FORMAT_R16_SSCALED VIRGL_FORMAT_R16_SSCALED
#define PIPE_FORMAT_R16G16_SSCALED VIRGL_FORMAT_R16G16_SSCALED
#define PIPE_FORMAT_R16G16B16_SSCALED VIRGL_FORMAT_R16G16B16_SSCALED
#define PIPE_FORMAT_R16G16B16A16_SSCALED VIRGL_FORMAT_R16G16B16A16_SSCALED
#define PIPE_FORMAT_R8_UNORM VIRGL_FORMAT_R8_UNORM
#define PIPE_FORMAT_R8G8_UNORM VIRGL_FORMAT_R8G8_UNORM
#define PIPE_FORMAT_R8G8B8_UNORM VIRGL_FORMAT_R8G8B8_UNORM
#define PIPE_FORMAT_R8G8B8A8_UNORM VIRGL_FORMAT_R8G8B8A8_UNORM
#define PIPE_FORMAT_X8B8G8R8_UNORM VIRGL_FORMAT_X8B8G8R8_UNORM
#define PIPE_FORMAT_R8_USCALED VIRGL_FORMAT_R8_USCALED
#define PIPE_FORMAT_R8G8_USCALED VIRGL_FORMAT_R8G8_USCALED
#define PIPE_FORMAT_R8G8B8_USCALED VIRGL_FORMAT_R8G8B8_USCALED
#define PIPE_FORMAT_R8G8B8A8_USCALED VIRGL_FORMAT_R8G8B8A8_USCALED
#define PIPE_FORMAT_R8_SNORM VIRGL_FORMAT_R8_SNORM
#define PIPE_FORMAT_R8G8_SNORM VIRGL_FORMAT_R8G8_SNORM
#define PIPE_FORMAT_R8G8B8_SNORM VIRGL_FORMAT_R8G8B8_SNORM
#define PIPE_FORMAT_R8G8B8A8_SNORM VIRGL_FORMAT_R8G8B8A8_SNORM
#define PIPE_FORMAT_R8_SSCALED VIRGL_FORMAT_R8_SSCALED
#define PIPE_FORMAT_R8G8_SSCALED VIRGL_FORMAT_R8G8_SSCALED
#define PIPE_FORMAT_R8G8B8_SSCALED VIRGL_FORMAT_R8G8B8_SSCALED
#define PIPE_FORMAT_R8G8B8A8_SSCALED VIRGL_FORMAT_R8G8B8A8_SSCALED
#define PIPE_FORMAT_R32_FIXED VIRGL_FORMAT_R32_FIXED
#define PIPE_FORMAT_R32G32_FIXED VIRGL_FORMAT_R32G32_FIXED
#define PIPE_FORMAT_R32G32B32_FIXED VIRGL_FORMAT_R32G32B32_FIXED
#define PIPE_FORMAT_R32G32B32A32_FIXED VIRGL_FORMAT_R32G32B32A32_FIXED
#define PIPE_FORMAT_R16_FLOAT VIRGL_FORMAT_R16_FLOAT
#define PIPE_FORMAT_R16G16_FLOAT VIRGL_FORMAT_R16G16_FLOAT
#define PIPE_FORMAT_R16G16B16_FLOAT VIRGL_FORMAT_R16G16B16_FLOAT
#define PIPE_FORMAT_R16G16B16A16_FLOAT VIRGL_FORMAT_R16G16B16A16_FLOAT

/* sRGB formats */
#define PIPE_FORMAT_L8_SRGB VIRGL_FORMAT_L8_SRGB
#define PIPE_FORMAT_L8A8_SRGB VIRGL_FORMAT_L8A8_SRGB
#define PIPE_FORMAT_R8G8_SRGB VIRGL_FORMAT_R8G8_SRGB
#define PIPE_FORMAT_R8G8B8_SRGB VIRGL_FORMAT_R8G8B8_SRGB
#define PIPE_FORMAT_A8B8G8R8_SRGB VIRGL_FORMAT_A8B8G8R8_SRGB
#define PIPE_FORMAT_X8B8G8R8_SRGB VIRGL_FORMAT_X8B8G8R8_SRGB
#define PIPE_FORMAT_B8G8R8A8_SRGB VIRGL_FORMAT_B8G8R8A8_SRGB
#define PIPE_FORMAT_B8G8R8X8_SRGB VIRGL_FORMAT_B8G8R8X8_SRGB
#define PIPE_FORMAT_A8R8G8B8_SRGB VIRGL_FORMAT_A8R8G8B8_SRGB
#define PIPE_FORMAT_X8R8G8B8_SRGB VIRGL_FORMAT_X8R8G8B8_SRGB
#define PIPE_FORMAT_R8G8B8A8_SRGB VIRGL_FORMAT_R8G8B8A8_SRGB

/* compressed formats */
#define PIPE_FORMAT_DXT1_RGB VIRGL_FORMAT_DXT1_RGB
#define PIPE_FORMAT_DXT1_RGBA VIRGL_FORMAT_DXT1_RGBA
#define PIPE_FORMAT_DXT3_RGBA VIRGL_FORMAT_DXT3_RGBA
#define PIPE_FORMAT_DXT5_RGBA VIRGL_FORMAT_DXT5_RGBA

/* sRGB, compressed */
#define PIPE_FORMAT_DXT1_SRGB VIRGL_FORMAT_DXT1_SRGB
#define PIPE_FORMAT_DXT1_SRGBA VIRGL_FORMAT_DXT1_SRGBA
#define PIPE_FORMAT_DXT3_SRGBA VIRGL_FORMAT_DXT3_SRGBA
#define PIPE_FORMAT_DXT5_SRGBA VIRGL_FORMAT_DXT5_SRGBA

/* rgtc compressed */
#define PIPE_FORMAT_RGTC1_UNORM VIRGL_FORMAT_RGTC1_UNORM
#define PIPE_FORMAT_RGTC1_SNORM VIRGL_FORMAT_RGTC1_SNORM
#define PIPE_FORMAT_RGTC2_UNORM VIRGL_FORMAT_RGTC2_UNORM
#define PIPE_FORMAT_RGTC2_SNORM VIRGL_FORMAT_RGTC2_SNORM

#define PIPE_FORMAT_R8G8_B8G8_UNORM VIRGL_FORMAT_R8G8_B8G8_UNORM
#define PIPE_FORMAT_G8R8_G8B8_UNORM VIRGL_FORMAT_G8R8_G8B8_UNORM

/* mixed formats */
#define PIPE_FORMAT_R8SG8SB8UX8U_NORM VIRGL_FORMAT_R8SG8SB8UX8U_NORM
#define PIPE_FORMAT_R5SG5SB6U_NORM VIRGL_FORMAT_R5SG5SB6U_NORM

/* TODO: re-order these */
#define PIPE_FORMAT_A8B8G8R8_UNORM VIRGL_FORMAT_A8B8G8R8_UNORM
#define PIPE_FORMAT_B5G5R5X1_UNORM VIRGL_FORMAT_B5G5R5X1_UNORM
#define PIPE_FORMAT_R10G10B10A2_USCALED VIRGL_FORMAT_R10G10B10A2_USCALED
#define PIPE_FORMAT_R11G11B10_FLOAT VIRGL_FORMAT_R11G11B10_FLOAT
#define PIPE_FORMAT_R9G9B9E5_FLOAT VIRGL_FORMAT_R9G9B9E5_FLOAT
#define PIPE_FORMAT_Z32_FLOAT_S8X24_UINT VIRGL_FORMAT_Z32_FLOAT_S8X24_UINT
#define PIPE_FORMAT_R1_UNORM VIRGL_FORMAT_R1_UNORM
#define PIPE_FORMAT_R10G10B10X2_USCALED VIRGL_FORMAT_R10G10B10X2_USCALED
#define PIPE_FORMAT_R10G10B10X2_SNORM VIRGL_FORMAT_R10G10B10X2_SNORM
#define PIPE_FORMAT_L4A4_UNORM VIRGL_FORMAT_L4A4_UNORM
#define PIPE_FORMAT_B10G10R10A2_UNORM VIRGL_FORMAT_B10G10R10A2_UNORM
#define PIPE_FORMAT_R10SG10SB10SA2U_NORM VIRGL_FORMAT_R10SG10SB10SA2U_NORM
#define PIPE_FORMAT_R8G8Bx_SNORM VIRGL_FORMAT_R8G8Bx_SNORM
#define PIPE_FORMAT_R8G8B8X8_UNORM VIRGL_FORMAT_R8G8B8X8_UNORM
#define PIPE_FORMAT_B4G4R4X4_UNORM VIRGL_FORMAT_B4G4R4X4_UNORM

/* some stencil samplers formats */
#define PIPE_FORMAT_X24S8_UINT VIRGL_FORMAT_X24S8_UINT
#define PIPE_FORMAT_S8X24_UINT VIRGL_FORMAT_S8X24_UINT
#define PIPE_FORMAT_X32_S8X24_UINT VIRGL_FORMAT_X32_S8X24_UINT

#define PIPE_FORMAT_B2G3R3_UNORM VIRGL_FORMAT_B2G3R3_UNORM
#define PIPE_FORMAT_L16A16_UNORM VIRGL_FORMAT_L16A16_UNORM
#define PIPE_FORMAT_A16_UNORM VIRGL_FORMAT_A16_UNORM
#define PIPE_FORMAT_I16_UNORM VIRGL_FORMAT_I16_UNORM

#define PIPE_FORMAT_LATC1_UNORM VIRGL_FORMAT_LATC1_UNORM
#define PIPE_FORMAT_LATC1_SNORM VIRGL_FORMAT_LATC1_SNORM
#define PIPE_FORMAT_LATC2_UNORM VIRGL_FORMAT_LATC2_UNORM
#define PIPE_FORMAT_LATC2_SNORM VIRGL_FORMAT_LATC2_SNORM

#define PIPE_FORMAT_A8_SNORM VIRGL_FORMAT_A8_SNORM
#define PIPE_FORMAT_L8_SNORM VIRGL_FORMAT_L8_SNORM
#define PIPE_FORMAT_L8A8_SNORM VIRGL_FORMAT_L8A8_SNORM
#define PIPE_FORMAT_I8_SNORM VIRGL_FORMAT_I8_SNORM
#define PIPE_FORMAT_A16_SNORM VIRGL_FORMAT_A16_SNORM
#define PIPE_FORMAT_L16_SNORM VIRGL_FORMAT_L16_SNORM
#define PIPE_FORMAT_L16A16_SNORM VIRGL_FORMAT_L16A16_SNORM
#define PIPE_FORMAT_I16_SNORM VIRGL_FORMAT_I16_SNORM

#define PIPE_FORMAT_A16_FLOAT VIRGL_FORMAT_A16_FLOAT
#define PIPE_FORMAT_L16_FLOAT VIRGL_FORMAT_L16_FLOAT
#define PIPE_FORMAT_L16A16_FLOAT VIRGL_FORMAT_L16A16_FLOAT
#define PIPE_FORMAT_I16_FLOAT VIRGL_FORMAT_I16_FLOAT
#define PIPE_FORMAT_A32_FLOAT VIRGL_FORMAT_A32_FLOAT
#define PIPE_FORMAT_L32_FLOAT VIRGL_FORMAT_L32_FLOAT
#define PIPE_FORMAT_L32A32_FLOAT VIRGL_FORMAT_L32A32_FLOAT
#define PIPE_FORMAT_I32_FLOAT VIRGL_FORMAT_I32_FLOAT

#define PIPE_FORMAT_YV12 VIRGL_FORMAT_YV12
#define PIPE_FORMAT_YV16 VIRGL_FORMAT_YV16
#define PIPE_FORMAT_IYUV VIRGL_FORMAT_IYUV                      /**< aka I420 */
#define PIPE_FORMAT_NV12 VIRGL_FORMAT_NV12
#define PIPE_FORMAT_NV21 VIRGL_FORMAT_NV21

#define PIPE_FORMAT_A4R4_UNORM VIRGL_FORMAT_A4R4_UNORM
#define PIPE_FORMAT_R4A4_UNORM VIRGL_FORMAT_R4A4_UNORM
#define PIPE_FORMAT_R8A8_UNORM VIRGL_FORMAT_R8A8_UNORM
#define PIPE_FORMAT_A8R8_UNORM VIRGL_FORMAT_A8R8_UNORM

#define PIPE_FORMAT_R10G10B10A2_SSCALED VIRGL_FORMAT_R10G10B10A2_SSCALED
#define PIPE_FORMAT_R10G10B10A2_SNORM VIRGL_FORMAT_R10G10B10A2_SNORM

#define PIPE_FORMAT_B10G10R10A2_USCALED VIRGL_FORMAT_B10G10R10A2_USCALED
#define PIPE_FORMAT_B10G10R10A2_SSCALED VIRGL_FORMAT_B10G10R10A2_SSCALED
#define PIPE_FORMAT_B10G10R10A2_SNORM VIRGL_FORMAT_B10G10R10A2_SNORM

#define PIPE_FORMAT_R8_UINT VIRGL_FORMAT_R8_UINT
#define PIPE_FORMAT_R8G8_UINT VIRGL_FORMAT_R8G8_UINT
#define PIPE_FORMAT_R8G8B8_UINT VIRGL_FORMAT_R8G8B8_UINT
#define PIPE_FORMAT_R8G8B8A8_UINT VIRGL_FORMAT_R8G8B8A8_UINT

#define PIPE_FORMAT_R8_SINT VIRGL_FORMAT_R8_SINT
#define PIPE_FORMAT_R8G8_SINT VIRGL_FORMAT_R8G8_SINT
#define PIPE_FORMAT_R8G8B8_SINT VIRGL_FORMAT_R8G8B8_SINT
#define PIPE_FORMAT_R8G8B8A8_SINT VIRGL_FORMAT_R8G8B8A8_SINT

#define PIPE_FORMAT_R16_UINT VIRGL_FORMAT_R16_UINT
#define PIPE_FORMAT_R16G16_UINT VIRGL_FORMAT_R16G16_UINT
#define PIPE_FORMAT_R16G16B16_UINT VIRGL_FORMAT_R16G16B16_UINT
#define PIPE_FORMAT_R16G16B16A16_UINT VIRGL_FORMAT_R16G16B16A16_UINT

#define PIPE_FORMAT_R16_SINT VIRGL_FORMAT_R16_SINT
#define PIPE_FORMAT_R16G16_SINT VIRGL_FORMAT_R16G16_SINT
#define PIPE_FORMAT_R16G16B16_SINT VIRGL_FORMAT_R16G16B16_SINT
#define PIPE_FORMAT_R16G16B16A16_SINT VIRGL_FORMAT_R16G16B16A16_SINT

#define PIPE_FORMAT_R32_UINT VIRGL_FORMAT_R32_UINT
#define PIPE_FORMAT_R32G32_UINT VIRGL_FORMAT_R32G32_UINT
#define PIPE_FORMAT_R32G32B32_UINT VIRGL_FORMAT_R32G32B32_UINT
#define PIPE_FORMAT_R32G32B32A32_UINT VIRGL_FORMAT_R32G32B32A32_UINT

#define PIPE_FORMAT_R32_SINT VIRGL_FORMAT_R32_SINT
#define PIPE_FORMAT_R32G32_SINT VIRGL_FORMAT_R32G32_SINT
#define PIPE_FORMAT_R32G32B32_SINT VIRGL_FORMAT_R32G32B32_SINT
#define PIPE_FORMAT_R32G32B32A32_SINT VIRGL_FORMAT_R32G32B32A32_SINT

#define PIPE_FORMAT_A8_UINT VIRGL_FORMAT_A8_UINT
#define PIPE_FORMAT_I8_UINT VIRGL_FORMAT_I8_UINT
#define PIPE_FORMAT_L8_UINT VIRGL_FORMAT_L8_UINT
#define PIPE_FORMAT_L8A8_UINT VIRGL_FORMAT_L8A8_UINT

#define PIPE_FORMAT_A8_SINT VIRGL_FORMAT_A8_SINT
#define PIPE_FORMAT_I8_SINT VIRGL_FORMAT_I8_SINT
#define PIPE_FORMAT_L8_SINT VIRGL_FORMAT_L8_SINT
#define PIPE_FORMAT_L8A8_SINT VIRGL_FORMAT_L8A8_SINT

#define PIPE_FORMAT_A16_UINT VIRGL_FORMAT_A16_UINT
#define PIPE_FORMAT_I16_UINT VIRGL_FORMAT_I16_UINT
#define PIPE_FORMAT_L16_UINT VIRGL_FORMAT_L16_UINT
#define PIPE_FORMAT_L16A16_UINT VIRGL_FORMAT_L16A16_UINT

#define PIPE_FORMAT_A16_SINT VIRGL_FORMAT_A16_SINT
#define PIPE_FORMAT_I16_SINT VIRGL_FORMAT_I16_SINT
#define PIPE_FORMAT_L16_SINT VIRGL_FORMAT_L16_SINT
#define PIPE_FORMAT_L16A16_SINT VIRGL_FORMAT_L16A16_SINT

#define PIPE_FORMAT_A32_UINT VIRGL_FORMAT_A32_UINT
#define PIPE_FORMAT_I32_UINT VIRGL_FORMAT_I32_UINT
#define PIPE_FORMAT_L32_UINT VIRGL_FORMAT_L32_UINT
#define PIPE_FORMAT_L32A32_UINT VIRGL_FORMAT_L32A32_UINT

#define PIPE_FORMAT_A32_SINT VIRGL_FORMAT_A32_SINT
#define PIPE_FORMAT_I32_SINT VIRGL_FORMAT_I32_SINT
#define PIPE_FORMAT_L32_SINT VIRGL_FORMAT_L32_SINT
#define PIPE_FORMAT_L32A32_SINT VIRGL_FORMAT_L32A32_SINT

#define PIPE_FORMAT_B10G10R10A2_UINT VIRGL_FORMAT_B10G10R10A2_UINT

#define PIPE_FORMAT_ETC1_RGB8 VIRGL_FORMAT_ETC1_RGB8

#define PIPE_FORMAT_R8G8_R8B8_UNORM VIRGL_FORMAT_R8G8_R8B8_UNORM
#define PIPE_FORMAT_G8R8_B8R8_UNORM VIRGL_FORMAT_G8R8_B8R8_UNORM

#define PIPE_FORMAT_R8G8B8X8_SNORM VIRGL_FORMAT_R8G8B8X8_SNORM
#define PIPE_FORMAT_R8G8B8X8_SRGB VIRGL_FORMAT_R8G8B8X8_SRGB
#define PIPE_FORMAT_R8G8B8X8_UINT VIRGL_FORMAT_R8G8B8X8_UINT
#define PIPE_FORMAT_R8G8B8X8_SINT VIRGL_FORMAT_R8G8B8X8_SINT
#define PIPE_FORMAT_B10G10R10X2_UNORM VIRGL_FORMAT_B10G10R10X2_UNORM
#define PIPE_FORMAT_R16G16B16X16_UNORM VIRGL_FORMAT_R16G16B16X16_UNORM
#define PIPE_FORMAT_R16G16B16X16_SNORM VIRGL_FORMAT_R16G16B16X16_SNORM
#define PIPE_FORMAT_R16G16B16X16_FLOAT VIRGL_FORMAT_R16G16B16X16_FLOAT
#define PIPE_FORMAT_R16G16B16X16_UINT VIRGL_FORMAT_R16G16B16X16_UINT
#define PIPE_FORMAT_R16G16B16X16_SINT VIRGL_FORMAT_R16G16B16X16_SINT
#define PIPE_FORMAT_R32G32B32X32_FLOAT VIRGL_FORMAT_R32G32B32X32_FLOAT
#define PIPE_FORMAT_R32G32B32X32_UINT VIRGL_FORMAT_R32G32B32X32_UINT
#define PIPE_FORMAT_R32G32B32X32_SINT VIRGL_FORMAT_R32G32B32X32_SINT

#define PIPE_FORMAT_R8A8_SNORM VIRGL_FORMAT_R8A8_SNORM
#define PIPE_FORMAT_R16A16_UNORM VIRGL_FORMAT_R16A16_UNORM
#define PIPE_FORMAT_R16A16_SNORM VIRGL_FORMAT_R16A16_SNORM
#define PIPE_FORMAT_R16A16_FLOAT VIRGL_FORMAT_R16A16_FLOAT
#define PIPE_FORMAT_R32A32_FLOAT VIRGL_FORMAT_R32A32_FLOAT
#define PIPE_FORMAT_R8A8_UINT VIRGL_FORMAT_R8A8_UINT
#define PIPE_FORMAT_R8A8_SINT VIRGL_FORMAT_R8A8_SINT
#define PIPE_FORMAT_R16A16_UINT VIRGL_FORMAT_R16A16_UINT
#define PIPE_FORMAT_R16A16_SINT VIRGL_FORMAT_R16A16_SINT
#define PIPE_FORMAT_R32A32_UINT VIRGL_FORMAT_R32A32_UINT
#define PIPE_FORMAT_R32A32_SINT VIRGL_FORMAT_R32A32_SINT
#define PIPE_FORMAT_R10G10B10A2_UINT VIRGL_FORMAT_R10G10B10A2_UINT

#define PIPE_FORMAT_B5G6R5_SRGB VIRGL_FORMAT_B5G6R5_SRGB

#define PIPE_FORMAT_BPTC_RGBA_UNORM VIRGL_FORMAT_BPTC_RGBA_UNORM
#define PIPE_FORMAT_BPTC_SRGBA VIRGL_FORMAT_BPTC_SRGBA
#define PIPE_FORMAT_BPTC_RGB_FLOAT VIRGL_FORMAT_BPTC_RGB_FLOAT
#define PIPE_FORMAT_BPTC_RGB_UFLOAT VIRGL_FORMAT_BPTC_RGB_UFLOAT

#define PIPE_FORMAT_A8L8_UNORM VIRGL_FORMAT_A8L8_UNORM
#define PIPE_FORMAT_A8L8_SNORM VIRGL_FORMAT_A8L8_SNORM
#define PIPE_FORMAT_A8L8_SRGB VIRGL_FORMAT_A8L8_SRGB
#define PIPE_FORMAT_A16L16_UNORM VIRGL_FORMAT_A16L16_UNORM

#define PIPE_FORMAT_G8R8_UNORM VIRGL_FORMAT_G8R8_UNORM
#define PIPE_FORMAT_G8R8_SNORM VIRGL_FORMAT_G8R8_SNORM
#define PIPE_FORMAT_G16R16_UNORM VIRGL_FORMAT_G16R16_UNORM
#define PIPE_FORMAT_G16R16_SNORM VIRGL_FORMAT_G16R16_SNORM

#define PIPE_FORMAT_A8B8G8R8_SNORM VIRGL_FORMAT_A8B8G8R8_SNORM
#define PIPE_FORMAT_X8B8G8R8_SNORM VIRGL_FORMAT_X8B8G8R8_SNORM

#define PIPE_FORMAT_ETC2_RGB8 VIRGL_FORMAT_ETC2_RGB8
#define PIPE_FORMAT_ETC2_SRGB8 VIRGL_FORMAT_ETC2_SRGB8
#define PIPE_FORMAT_ETC2_RGB8A1 VIRGL_FORMAT_ETC2_RGB8A1
#define PIPE_FORMAT_ETC2_SRGB8A1 VIRGL_FORMAT_ETC2_SRGB8A1
#define PIPE_FORMAT_ETC2_RGBA8 VIRGL_FORMAT_ETC2_RGBA8
#define PIPE_FORMAT_ETC2_SRGBA8 VIRGL_FORMAT_ETC2_SRGBA8
#define PIPE_FORMAT_ETC2_R11_UNORM VIRGL_FORMAT_ETC2_R11_UNORM
#define PIPE_FORMAT_ETC2_R11_SNORM VIRGL_FORMAT_ETC2_R11_SNORM
#define PIPE_FORMAT_ETC2_RG11_UNORM VIRGL_FORMAT_ETC2_RG11_UNORM
#define PIPE_FORMAT_ETC2_RG11_SNORM VIRGL_FORMAT_ETC2_RG11_SNORM

#define PIPE_FORMAT_ASTC_4x4 VIRGL_FORMAT_ASTC_4x4
#define PIPE_FORMAT_ASTC_5x4 VIRGL_FORMAT_ASTC_5x4
#define PIPE_FORMAT_ASTC_5x5 VIRGL_FORMAT_ASTC_5x5
#define PIPE_FORMAT_ASTC_6x5 VIRGL_FORMAT_ASTC_6x5
#define PIPE_FORMAT_ASTC_6x6 VIRGL_FORMAT_ASTC_6x6
#define PIPE_FORMAT_ASTC_8x5 VIRGL_FORMAT_ASTC_8x5
#define PIPE_FORMAT_ASTC_8x6 VIRGL_FORMAT_ASTC_8x6
#define PIPE_FORMAT_ASTC_8x8 VIRGL_FORMAT_ASTC_8x8
#define PIPE_FORMAT_ASTC_10x5 VIRGL_FORMAT_ASTC_10x5
#define PIPE_FORMAT_ASTC_10x6 VIRGL_FORMAT_ASTC_10x6
#define PIPE_FORMAT_ASTC_10x8 VIRGL_FORMAT_ASTC_10x8
#define PIPE_FORMAT_ASTC_10x10 VIRGL_FORMAT_ASTC_10x10
#define PIPE_FORMAT_ASTC_12x10 VIRGL_FORMAT_ASTC_12x10
#define PIPE_FORMAT_ASTC_12x12 VIRGL_FORMAT_ASTC_12x12

#define PIPE_FORMAT_ASTC_4x4_SRGB VIRGL_FORMAT_ASTC_4x4_SRGB
#define PIPE_FORMAT_ASTC_5x4_SRGB VIRGL_FORMAT_ASTC_5x4_SRGB
#define PIPE_FORMAT_ASTC_5x5_SRGB VIRGL_FORMAT_ASTC_5x5_SRGB
#define PIPE_FORMAT_ASTC_6x5_SRGB VIRGL_FORMAT_ASTC_6x5_SRGB
#define PIPE_FORMAT_ASTC_6x6_SRGB VIRGL_FORMAT_ASTC_6x6_SRGB
#define PIPE_FORMAT_ASTC_8x5_SRGB VIRGL_FORMAT_ASTC_8x5_SRGB
#define PIPE_FORMAT_ASTC_8x6_SRGB VIRGL_FORMAT_ASTC_8x6_SRGB
#define PIPE_FORMAT_ASTC_8x8_SRGB VIRGL_FORMAT_ASTC_8x8_SRGB
#define PIPE_FORMAT_ASTC_10x5_SRGB VIRGL_FORMAT_ASTC_10x5_SRGB
#define PIPE_FORMAT_ASTC_10x6_SRGB VIRGL_FORMAT_ASTC_10x6_SRGB
#define PIPE_FORMAT_ASTC_10x8_SRGB VIRGL_FORMAT_ASTC_10x8_SRGB
#define PIPE_FORMAT_ASTC_10x10_SRGB VIRGL_FORMAT_ASTC_10x10_SRGB
#define PIPE_FORMAT_ASTC_12x10_SRGB VIRGL_FORMAT_ASTC_12x10_SRGB
#define PIPE_FORMAT_ASTC_12x12_SRGB VIRGL_FORMAT_ASTC_12x12_SRGB

#define PIPE_FORMAT_P016 VIRGL_FORMAT_P016

#define PIPE_FORMAT_R10G10B10X2_UNORM VIRGL_FORMAT_R10G10B10X2_UNORM
#define PIPE_FORMAT_A1B5G5R5_UNORM VIRGL_FORMAT_A1B5G5R5_UNORM
#define PIPE_FORMAT_X1B5G5R5_UNORM VIRGL_FORMAT_X1B5G5R5_UNORM
#define PIPE_FORMAT_A4B4G4R4_UNORM VIRGL_FORMAT_A4B4G4R4_UNORM

#define PIPE_FORMAT_R8_SRGB VIRGL_FORMAT_R8_SRGB

#define PIPE_FORMAT_COUNT VIRGL_FORMAT_MAX

#if UTIL_ARCH_LITTLE_ENDIAN
#define PIPE_FORMAT_RGBA8888_UNORM PIPE_FORMAT_R8G8B8A8_UNORM
#define PIPE_FORMAT_RGBX8888_UNORM PIPE_FORMAT_R8G8B8X8_UNORM
#define PIPE_FORMAT_BGRA8888_UNORM PIPE_FORMAT_B8G8R8A8_UNORM
#define PIPE_FORMAT_BGRX8888_UNORM PIPE_FORMAT_B8G8R8X8_UNORM
#define PIPE_FORMAT_ARGB8888_UNORM PIPE_FORMAT_A8R8G8B8_UNORM
#define PIPE_FORMAT_XRGB8888_UNORM PIPE_FORMAT_X8R8G8B8_UNORM
#define PIPE_FORMAT_ABGR8888_UNORM PIPE_FORMAT_A8B8G8R8_UNORM
#define PIPE_FORMAT_XBGR8888_UNORM PIPE_FORMAT_X8B8G8R8_UNORM
#define PIPE_FORMAT_RGBA8888_SNORM PIPE_FORMAT_R8G8B8A8_SNORM
#define PIPE_FORMAT_RGBX8888_SNORM PIPE_FORMAT_R8G8B8X8_SNORM
#define PIPE_FORMAT_ABGR8888_SNORM PIPE_FORMAT_A8B8G8R8_SNORM
#define PIPE_FORMAT_XBGR8888_SNORM PIPE_FORMAT_X8B8G8R8_SNORM
#define PIPE_FORMAT_RGBA8888_SRGB PIPE_FORMAT_R8G8B8A8_SRGB
#define PIPE_FORMAT_RGBX8888_SRGB PIPE_FORMAT_R8G8B8X8_SRGB
#define PIPE_FORMAT_BGRA8888_SRGB PIPE_FORMAT_B8G8R8A8_SRGB
#define PIPE_FORMAT_BGRX8888_SRGB PIPE_FORMAT_B8G8R8X8_SRGB
#define PIPE_FORMAT_ARGB8888_SRGB PIPE_FORMAT_A8R8G8B8_SRGB
#define PIPE_FORMAT_XRGB8888_SRGB PIPE_FORMAT_X8R8G8B8_SRGB
#define PIPE_FORMAT_ABGR8888_SRGB PIPE_FORMAT_A8B8G8R8_SRGB
#define PIPE_FORMAT_XBGR8888_SRGB PIPE_FORMAT_X8B8G8R8_SRGB
#define PIPE_FORMAT_LA88_UNORM PIPE_FORMAT_L8A8_UNORM
#define PIPE_FORMAT_AL88_UNORM PIPE_FORMAT_A8L8_UNORM
#define PIPE_FORMAT_LA88_SNORM PIPE_FORMAT_L8A8_SNORM
#define PIPE_FORMAT_AL88_SNORM PIPE_FORMAT_A8L8_SNORM
#define PIPE_FORMAT_LA88_SRGB PIPE_FORMAT_L8A8_SRGB
#define PIPE_FORMAT_AL88_SRGB PIPE_FORMAT_A8L8_SRGB
#define PIPE_FORMAT_LA1616_UNORM PIPE_FORMAT_L16A16_UNORM
#define PIPE_FORMAT_AL1616_UNORM PIPE_FORMAT_A16L16_UNORM
#define PIPE_FORMAT_RG88_UNORM PIPE_FORMAT_R8G8_UNORM
#define PIPE_FORMAT_GR88_UNORM PIPE_FORMAT_G8R8_UNORM
#define PIPE_FORMAT_RG88_SNORM PIPE_FORMAT_R8G8_SNORM
#define PIPE_FORMAT_GR88_SNORM PIPE_FORMAT_G8R8_SNORM
#define PIPE_FORMAT_RG1616_UNORM PIPE_FORMAT_R16G16_UNORM
#define PIPE_FORMAT_GR1616_UNORM PIPE_FORMAT_G16R16_UNORM
#define PIPE_FORMAT_RG1616_SNORM PIPE_FORMAT_R16G16_SNORM
#define PIPE_FORMAT_GR1616_SNORM PIPE_FORMAT_G16R16_SNORM
#elif UTIL_ARCH_BIG_ENDIAN
#define PIPE_FORMAT_ABGR8888_UNORM PIPE_FORMAT_R8G8B8A8_UNORM
#define PIPE_FORMAT_XBGR8888_UNORM PIPE_FORMAT_R8G8B8X8_UNORM
#define PIPE_FORMAT_ARGB8888_UNORM PIPE_FORMAT_B8G8R8A8_UNORM
#define PIPE_FORMAT_XRGB8888_UNORM PIPE_FORMAT_B8G8R8X8_UNORM
#define PIPE_FORMAT_BGRA8888_UNORM PIPE_FORMAT_A8R8G8B8_UNORM
#define PIPE_FORMAT_BGRX8888_UNORM PIPE_FORMAT_X8R8G8B8_UNORM
#define PIPE_FORMAT_RGBA8888_UNORM PIPE_FORMAT_A8B8G8R8_UNORM
#define PIPE_FORMAT_RGBX8888_UNORM PIPE_FORMAT_X8B8G8R8_UNORM
#define PIPE_FORMAT_ABGR8888_SNORM PIPE_FORMAT_R8G8B8A8_SNORM
#define PIPE_FORMAT_XBGR8888_SNORM PIPE_FORMAT_R8G8B8X8_SNORM
#define PIPE_FORMAT_RGBA8888_SNORM PIPE_FORMAT_A8B8G8R8_SNORM
#define PIPE_FORMAT_RGBX8888_SNORM PIPE_FORMAT_X8B8G8R8_SNORM
#define PIPE_FORMAT_ABGR8888_SRGB PIPE_FORMAT_R8G8B8A8_SRGB
#define PIPE_FORMAT_XBGR8888_SRGB PIPE_FORMAT_R8G8B8X8_SRGB
#define PIPE_FORMAT_ARGB8888_SRGB PIPE_FORMAT_B8G8R8A8_SRGB
#define PIPE_FORMAT_XRGB8888_SRGB PIPE_FORMAT_B8G8R8X8_SRGB
#define PIPE_FORMAT_BGRA8888_SRGB PIPE_FORMAT_A8R8G8B8_SRGB
#define PIPE_FORMAT_BGRX8888_SRGB PIPE_FORMAT_X8R8G8B8_SRGB
#define PIPE_FORMAT_RGBA8888_SRGB PIPE_FORMAT_A8B8G8R8_SRGB
#define PIPE_FORMAT_RGBX8888_SRGB PIPE_FORMAT_X8B8G8R8_SRGB
#define PIPE_FORMAT_LA88_UNORM PIPE_FORMAT_A8L8_UNORM
#define PIPE_FORMAT_AL88_UNORM PIPE_FORMAT_L8A8_UNORM
#define PIPE_FORMAT_LA88_SNORM PIPE_FORMAT_A8L8_SNORM
#define PIPE_FORMAT_AL88_SNORM PIPE_FORMAT_L8A8_SNORM
#define PIPE_FORMAT_LA88_SRGB PIPE_FORMAT_A8L8_SRGB
#define PIPE_FORMAT_AL88_SRGB PIPE_FORMAT_L8A8_SRGB
#define PIPE_FORMAT_LA1616_UNORM PIPE_FORMAT_A16L16_UNORM
#define PIPE_FORMAT_AL1616_UNORM PIPE_FORMAT_L16A16_UNORM
#define PIPE_FORMAT_RG88_UNORM PIPE_FORMAT_G8R8_UNORM
#define PIPE_FORMAT_GR88_UNORM PIPE_FORMAT_R8G8_UNORM
#define PIPE_FORMAT_RG88_SNORM PIPE_FORMAT_G8R8_SNORM
#define PIPE_FORMAT_GR88_SNORM PIPE_FORMAT_R8G8_SNORM
#define PIPE_FORMAT_RG1616_UNORM PIPE_FORMAT_G16R16_UNORM
#define PIPE_FORMAT_GR1616_UNORM PIPE_FORMAT_R16G16_UNORM
#define PIPE_FORMAT_RG1616_SNORM PIPE_FORMAT_G16R16_SNORM
#define PIPE_FORMAT_GR1616_SNORM PIPE_FORMAT_R16G16_SNORM
#endif

enum pipe_video_chroma_format
{
   PIPE_VIDEO_CHROMA_FORMAT_400,
   PIPE_VIDEO_CHROMA_FORMAT_420,
   PIPE_VIDEO_CHROMA_FORMAT_422,
   PIPE_VIDEO_CHROMA_FORMAT_444,
   PIPE_VIDEO_CHROMA_FORMAT_NONE
};

#ifdef __cplusplus
}
#endif

#endif
