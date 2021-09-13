/****************************************************************************
 Copyright (c) 2020 Xiamen Yaji Software Co., Ltd.

http://www.cocos.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "ModoJSBridge.h"

namespace cc {

ModoJSBridge *__instance = nullptr;

ModoJSBridge *ModoJSBridge::getInstance() {
    if (__instance == nullptr) {
        __instance = new ModoJSBridge();
    }
    return __instance;
}

void ModoJSBridge::setNativeJSBridgeCallback(const ModoJSBridgeCallback &cb) {
    _nativeJSBridgeCallBack = cb;
}

void ModoJSBridge::callNativeJSBridgeCallback(const std::string &message) {
    if (_nativeJSBridgeCallBack) {
        _nativeJSBridgeCallBack(message);
    }
}

void ModoJSBridge::setSdkJSBridgeCallback(const ModoJSBridgeCallback &cb) {
    _sdkJSBridgeCallBack = cb;
}

void ModoJSBridge::callSdkJSBridgeCallback(const std::string &message) {
    if (_sdkJSBridgeCallBack) {
        _sdkJSBridgeCallBack(message);
    }
}

void ModoJSBridge::clearCustomJSBridgeCallback() {
    _nativeJSBridgeCallBack = nullptr;
    _sdkJSBridgeCallBack = nullptr;
}
} // namespace cc