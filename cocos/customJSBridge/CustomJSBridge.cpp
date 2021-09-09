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
#if CC_PLATFORM == CC_PLATFORM_ANDROID
#include <jni.h>
#include <cocos/platform/android/jni/JniHelper.h>
#endif // CC_PLATFORM == CC_PLATFORM_ANDROID
#include <boost/hana/string.hpp>
#include "CustomJSBridge.h"

namespace cc {

    CustomJSBridge *__instance = nullptr;

    CustomJSBridge *CustomJSBridge::getInstance() {
        if (__instance == nullptr) {
            __instance = new CustomJSBridge();
        }
        return __instance;
    }

    void CustomJSBridge::setNativeJSBridgeCallback(const CustomJSBridgeCallback &cb) {
        _nativeJSBridgeCallBack = cb;
    }

    void CustomJSBridge::callNativeJSBridgeCallback(const std::string &message) {
        if (_nativeJSBridgeCallBack) {
            _nativeJSBridgeCallBack(message);
        }
    }

    void CustomJSBridge::setSdkJSBridgeCallback(const CustomJSBridgeCallback &cb) {
        _sdkJSBridgeCallBack = cb;
    }

    void CustomJSBridge::callSdkJSBridgeCallback(const std::string &message) {
        if (_sdkJSBridgeCallBack) {
            _sdkJSBridgeCallBack(message);
        }
    }

    void CustomJSBridge::clearCustomJSBridgeCallback() {
        _nativeJSBridgeCallBack = nullptr;
        _sdkJSBridgeCallBack = nullptr;
    }
} // namespace cc

#if CC_PLATFORM == CC_PLATFORM_ANDROID
extern "C" {
static JavaVM *gVm = NULL;
JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    gVm = vm;
    return JNI_VERSION_1_6;
}
JNIEXPORT void JNICALL
Java_com_cocos_game_AppActivity_setNativeJSBridgeCallback(JNIEnv *env, jobject thiz) {
    auto func = [=](const std::string str) -> void {
        cc::JniHelper::callStaticVoidMethod("com/cocos/game/AppActivity", "nativeCallBack", str);
    };
    cc::CustomJSBridge::getInstance()->setNativeJSBridgeCallback(func);
}
JNIEXPORT void JNICALL
Java_com_cocos_game_AppActivity_callNativeJSBridgeCallback(JNIEnv *env, jobject thiz,
                                                           jstring prompt) {
    auto textStr = cc::JniHelper::jstring2string(prompt);
    cc::CustomJSBridge::getInstance()->callNativeJSBridgeCallback(textStr);
}
JNIEXPORT void JNICALL
Java_com_cocos_game_AppActivity_setSdkJSBridgeCallback(JNIEnv *env, jobject thiz) {
    auto func = [=](const std::string str) -> void {
        cc::JniHelper::callStaticVoidMethod("com/cocos/game/AppActivity", "sdkCallBack", str);
    };
    cc::CustomJSBridge::getInstance()->setSdkJSBridgeCallback(func);
}
JNIEXPORT void JNICALL
Java_com_cocos_game_AppActivity_callSdkJSBridgeCallback(JNIEnv *env, jobject thiz, jstring std) {
    auto textStr = cc::JniHelper::jstring2string(std);
    cc::CustomJSBridge::getInstance()->callSdkJSBridgeCallback(textStr);
}
JNIEXPORT void JNICALL
Java_com_cocos_game_AppActivity_clearCustomJSBridgeCallback(JNIEnv *env, jobject thiz) {
    cc::CustomJSBridge::getInstance()->clearCustomJSBridgeCallback();
}
}
#endif // CC_PLATFORM == CC_PLATFORM_ANDROID