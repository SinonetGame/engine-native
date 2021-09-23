#pragma once
#include "base/Config.h"
#include <type_traits>
#include "cocos/bindings/jswrapper/SeApi.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "cocos/customJSBridge/CustomJSBridge.h"

extern se::Object* __jsb_cc_CustomJSBridge_proto;
extern se::Class* __jsb_cc_CustomJSBridge_class;

bool js_register_cc_CustomJSBridge(se::Object* obj);
bool register_all_customJSBridge(se::Object* obj);

JSB_REGISTER_OBJECT_TYPE(cc::CustomJSBridge);
SE_DECLARE_FUNC(js_customJSBridge_CustomJSBridge_callXinnuoNativeJSBridgeCallback);
SE_DECLARE_FUNC(js_customJSBridge_CustomJSBridge_callXinnuoSdkJSBridgeCallback);
SE_DECLARE_FUNC(js_customJSBridge_CustomJSBridge_clearXinnuoCustomJSBridgeCallback);
SE_DECLARE_FUNC(js_customJSBridge_CustomJSBridge_setXinnuoNativeJSBridgeCallback);
SE_DECLARE_FUNC(js_customJSBridge_CustomJSBridge_setXinnuoSdkJSBridgeCallback);
SE_DECLARE_FUNC(js_customJSBridge_CustomJSBridge_getInstance);

