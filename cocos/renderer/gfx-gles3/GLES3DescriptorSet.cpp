/****************************************************************************
 Copyright (c) 2019-2021 Xiamen Yaji Software Co., Ltd.

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

#include "GLES3Std.h"

#include "GLES3Buffer.h"
#include "GLES3Commands.h"
#include "GLES3DescriptorSet.h"
#include "GLES3DescriptorSetLayout.h"
#include "GLES3Sampler.h"
#include "GLES3Texture.h"

namespace cc {
namespace gfx {

GLES3DescriptorSet::GLES3DescriptorSet() {
    _typedID = generateObjectID<decltype(this)>();
}

GLES3DescriptorSet::~GLES3DescriptorSet() {
    destroy();
}

void GLES3DescriptorSet::doInit(const DescriptorSetInfo & /*info*/) {
    const GLES3GPUDescriptorSetLayout *gpuDescriptorSetLayout = static_cast<GLES3DescriptorSetLayout *>(_layout)->gpuDescriptorSetLayout();
    const size_t                       descriptorCount        = gpuDescriptorSetLayout->descriptorCount;
    const size_t                       bindingCount           = gpuDescriptorSetLayout->bindings.size();

    _gpuDescriptorSet = CC_NEW(GLES3GPUDescriptorSet);
    _gpuDescriptorSet->gpuDescriptors.resize(descriptorCount);
    for (size_t i = 0U, k = 0U; i < bindingCount; i++) {
        const DescriptorSetLayoutBinding &binding = gpuDescriptorSetLayout->bindings[i];
        for (uint j = 0; j < binding.count; j++, k++) {
            _gpuDescriptorSet->gpuDescriptors[k].type = binding.descriptorType;
        }
    }

    _gpuDescriptorSet->descriptorIndices = &gpuDescriptorSetLayout->descriptorIndices;
}

void GLES3DescriptorSet::doDestroy() {
    if (_gpuDescriptorSet) {
        CC_DELETE(_gpuDescriptorSet);
        _gpuDescriptorSet = nullptr;
    }
}

void GLES3DescriptorSet::update() {
    if (_isDirty && _gpuDescriptorSet) {
        const GLES3GPUDescriptorList &descriptors = _gpuDescriptorSet->gpuDescriptors;
        for (size_t i = 0; i < descriptors.size(); i++) {
            if (hasAnyFlags(descriptors[i].type, DESCRIPTOR_BUFFER_TYPE)) {
                if (_buffers[i]) {
                    _gpuDescriptorSet->gpuDescriptors[i].gpuBuffer = static_cast<GLES3Buffer *>(_buffers[i])->gpuBuffer();
                }
            } else if (hasAnyFlags(descriptors[i].type, DESCRIPTOR_TEXTURE_TYPE)) {
                if (_textures[i]) {
                    _gpuDescriptorSet->gpuDescriptors[i].gpuTexture = static_cast<GLES3Texture *>(_textures[i])->gpuTexture();
                }
                if (_samplers[i]) {
                    _gpuDescriptorSet->gpuDescriptors[i].gpuSampler = static_cast<GLES3Sampler *>(_samplers[i])->gpuSampler();
                }
            }
        }
        _isDirty = false;
    }
}

} // namespace gfx
} // namespace cc
