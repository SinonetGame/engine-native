#pragma once
#include "base/Config.h"
#include <type_traits>
#include "cocos/bindings/jswrapper/SeApi.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "cocos/modoJSBridge/ModoJSBridge.h"

extern se::Object* __jsb_cc_ModoJSBridge_proto;
extern se::Class* __jsb_cc_ModoJSBridge_class;

bool js_register_cc_ModoJSBridge(se::Object* obj);
bool register_all_modoJSBridge(se::Object* obj);

JSB_REGISTER_OBJECT_TYPE(cc::ModoJSBridge);
SE_DECLARE_FUNC(js_modoJSBridge_ModoJSBridge_callNativeJSBridgeCallback);
SE_DECLARE_FUNC(js_modoJSBridge_ModoJSBridge_callSdkJSBridgeCallback);
SE_DECLARE_FUNC(js_modoJSBridge_ModoJSBridge_clearCustomJSBridgeCallback);
SE_DECLARE_FUNC(js_modoJSBridge_ModoJSBridge_setNativeJSBridgeCallback);
SE_DECLARE_FUNC(js_modoJSBridge_ModoJSBridge_setSdkJSBridgeCallback);
SE_DECLARE_FUNC(js_modoJSBridge_ModoJSBridge_getInstance);

