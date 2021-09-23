#include "cocos/bindings/auto/jsb_customJSBridge_auto.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "cocos/bindings/manual/jsb_global.h"
#include "customJSBridge/CustomJSBridge.h"

#ifndef JSB_ALLOC
#define JSB_ALLOC(kls, ...) new (std::nothrow) kls(__VA_ARGS__)
#endif

#ifndef JSB_FREE
#define JSB_FREE(ptr) delete ptr
#endif
se::Object* __jsb_cc_CustomJSBridge_proto = nullptr;
se::Class* __jsb_cc_CustomJSBridge_class = nullptr;

static bool js_customJSBridge_CustomJSBridge_callXinnuoNativeJSBridgeCallback(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_callXinnuoNativeJSBridgeCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        HolderType<std::string, true> arg0 = {};
        ok &= sevalue_to_native(args[0], &arg0, s.thisObject());
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_callXinnuoNativeJSBridgeCallback : Error processing arguments");
        cobj->callXinnuoNativeJSBridgeCallback(arg0.value());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_callXinnuoNativeJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_callXinnuoSdkJSBridgeCallback(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_callXinnuoSdkJSBridgeCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        HolderType<std::string, true> arg0 = {};
        ok &= sevalue_to_native(args[0], &arg0, s.thisObject());
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_callXinnuoSdkJSBridgeCallback : Error processing arguments");
        cobj->callXinnuoSdkJSBridgeCallback(arg0.value());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_callXinnuoSdkJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_clearXinnuoCustomJSBridgeCallback(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_clearXinnuoCustomJSBridgeCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clearXinnuoCustomJSBridgeCallback();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_clearXinnuoCustomJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_setXinnuoNativeJSBridgeCallback(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_setXinnuoNativeJSBridgeCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        HolderType<std::function<void (const std::string)>, true> arg0 = {};
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](const std::string larg0) -> void {
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= nativevalue_to_se(larg0, args[0], nullptr /*ctx*/);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg0.data = lambda;
            }
            else
            {
                arg0.data = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_setXinnuoNativeJSBridgeCallback : Error processing arguments");
        cobj->setXinnuoNativeJSBridgeCallback(arg0.value());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_setXinnuoNativeJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_setXinnuoSdkJSBridgeCallback(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_setXinnuoSdkJSBridgeCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        HolderType<std::function<void (const std::string)>, true> arg0 = {};
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachObject(jsFunc.toObject());
                auto lambda = [=](const std::string larg0) -> void {
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= nativevalue_to_se(larg0, args[0], nullptr /*ctx*/);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg0.data = lambda;
            }
            else
            {
                arg0.data = nullptr;
            }
        } while(false)
        ;
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_setXinnuoSdkJSBridgeCallback : Error processing arguments");
        cobj->setXinnuoSdkJSBridgeCallback(arg0.value());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_setXinnuoSdkJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_getInstance(se::State& s) // NOLINT(readability-identifier-naming)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cc::CustomJSBridge* result = cc::CustomJSBridge::getInstance();
        ok &= nativevalue_to_se(result, s.rval(), nullptr /*ctx*/);
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_getInstance : Error processing arguments");
        SE_HOLD_RETURN_VALUE(result, s.thisObject(), s.rval());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_getInstance)


static bool js_cc_CustomJSBridge_finalize(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(SE_THIS_OBJECT<cc::CustomJSBridge>(s));
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        auto* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
        JSB_FREE(cobj);
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cc_CustomJSBridge_finalize)

bool js_register_customJSBridge_CustomJSBridge(se::Object* obj) // NOLINT(readability-identifier-naming)
{
    auto* cls = se::Class::create("CustomJSBridge", obj, nullptr, nullptr);

    cls->defineFunction("callXinnuoNativeJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_callXinnuoNativeJSBridgeCallback));
    cls->defineFunction("callXinnuoSdkJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_callXinnuoSdkJSBridgeCallback));
    cls->defineFunction("clearXinnuoCustomJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_clearXinnuoCustomJSBridgeCallback));
    cls->defineFunction("setXinnuoNativeJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_setXinnuoNativeJSBridgeCallback));
    cls->defineFunction("setXinnuoSdkJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_setXinnuoSdkJSBridgeCallback));
    cls->defineStaticFunction("getInstance", _SE(js_customJSBridge_CustomJSBridge_getInstance));
    cls->defineFinalizeFunction(_SE(js_cc_CustomJSBridge_finalize));
    cls->install();
    JSBClassType::registerClass<cc::CustomJSBridge>(cls);

    __jsb_cc_CustomJSBridge_proto = cls->getProto();
    __jsb_cc_CustomJSBridge_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
bool register_all_customJSBridge(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("jsb", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("jsb", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_customJSBridge_CustomJSBridge(ns);
    return true;
}

