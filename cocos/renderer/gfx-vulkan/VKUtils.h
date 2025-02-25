/****************************************************************************
 Copyright (c) 2020-2021 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
****************************************************************************/

#pragma once

#define WIN32_LEAN_AND_MEAN

#include "base/Macros.h"
#include "base/StringUtil.h"
#include "base/Utils.h"
#include "gfx-base/GFXDef.h"

#include "vk_mem_alloc.h"
#include "volk.h"

#include "thsvs_simpler_vulkan_synchronization.h"

#define DEFAULT_TIMEOUT 10000000000 // 10 second

#define BARRIER_DEDUCTION_LEVEL_NONE  0
#define BARRIER_DEDUCTION_LEVEL_BASIC 1
#define BARRIER_DEDUCTION_LEVEL_FULL  2

#ifndef BARRIER_DEDUCTION_LEVEL
    #define BARRIER_DEDUCTION_LEVEL BARRIER_DEDUCTION_LEVEL_BASIC
#endif

namespace cc {
namespace gfx {

extern VkFormat              mapVkFormat(Format format);
extern VkAttachmentLoadOp    mapVkLoadOp(LoadOp loadOp);
extern VkAttachmentStoreOp   mapVkStoreOp(StoreOp storeOp);
extern VkBufferUsageFlagBits mapVkBufferUsageFlagBits(BufferUsage usage);
extern VkImageType           mapVkImageType(TextureType type);
extern VkFormatFeatureFlags  mapVkFormatFeatureFlags(TextureUsage usage);
extern VkImageUsageFlagBits  mapVkImageUsageFlagBits(TextureUsage usage);
extern VkImageAspectFlags    mapVkImageAspectFlags(Format format);
extern VkImageCreateFlags    mapVkImageCreateFlags(TextureType type);
extern VkImageViewType       mapVkImageViewType(TextureType viewType);
extern VkCommandBufferLevel  mapVkCommandBufferLevel(CommandBufferType type);
extern VkDescriptorType      mapVkDescriptorType(DescriptorType type);
extern VkColorComponentFlags mapVkColorComponentFlags(ColorMask colorMask);
extern VkShaderStageFlagBits mapVkShaderStageFlagBits(ShaderStageFlagBit stage);
extern VkShaderStageFlags    mapVkShaderStageFlags(ShaderStageFlagBit stages);
extern SurfaceTransform      mapSurfaceTransform(VkSurfaceTransformFlagBitsKHR transform);
extern String                mapVendorName(uint32_t vendorID);
extern void                  mapDepthStencilBits(Format format, uint *pDepthBits, uint *pStencilBits);

extern void         fullPipelineBarrier(VkCommandBuffer cmdBuff);
extern VkDeviceSize roundUp(VkDeviceSize numToRound, uint multiple);
extern bool         isLayerSupported(const char *required, const vector<VkLayerProperties> &available);
extern bool         isExtensionSupported(const char *required, const vector<VkExtensionProperties> &available);

extern const VkSurfaceTransformFlagsKHR TRANSFORMS_THAT_REQUIRE_FLIPPING;
extern const VkPrimitiveTopology        VK_PRIMITIVE_MODES[];
extern const VkCullModeFlags            VK_CULL_MODES[];
extern const VkPolygonMode              VK_POLYGON_MODES[];
extern const VkCompareOp                VK_CMP_FUNCS[];
extern const VkStencilOp                VK_STENCIL_OPS[];
extern const VkBlendOp                  VK_BLEND_OPS[];
extern const VkBlendFactor              VK_BLEND_FACTORS[];
extern const VkFilter                   VK_FILTERS[];
extern const VkSamplerMipmapMode        VK_SAMPLER_MIPMAP_MODES[];
extern const VkSamplerAddressMode       VK_SAMPLER_ADDRESS_MODES[];
extern const VkPipelineBindPoint        VK_PIPELINE_BIND_POINTS[];
extern const ThsvsAccessType            THSVS_ACCESS_TYPES[];
extern const VkResolveModeFlagBits      VK_RESOLVE_MODES[];
extern const VkImageLayout              VK_IMAGE_LAYOUTS[];
extern const VkStencilFaceFlags         VK_STENCIL_FACE_FLAGS[];
extern const VkAccessFlags              FULL_ACCESS_FLAGS;

} // namespace gfx
} // namespace cc
