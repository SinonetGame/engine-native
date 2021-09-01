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

static bool js_customJSBridge_CustomJSBridge_callNativeJSBridgeCallback(se::State& s)
{
    cc::CustomJSBridge* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_callNativeJSBridgeCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        HolderType<std::string, true> arg0 = {};
        ok &= sevalue_to_native(args[0], &arg0, s.thisObject());
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_callNativeJSBridgeCallback : Error processing arguments");
        cobj->callNativeJSBridgeCallback(arg0.value());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_callNativeJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_callSdkJSBridgeCallback(se::State& s)
{
    cc::CustomJSBridge* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_callSdkJSBridgeCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        HolderType<std::string, true> arg0 = {};
        ok &= sevalue_to_native(args[0], &arg0, s.thisObject());
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_callSdkJSBridgeCallback : Error processing arguments");
        cobj->callSdkJSBridgeCallback(arg0.value());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_callSdkJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_clearCustomJSBridgeCallback(se::State& s)
{
    cc::CustomJSBridge* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_clearCustomJSBridgeCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clearCustomJSBridgeCallback();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_clearCustomJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_setNativeJSBridgeCallback(se::State& s)
{
    cc::CustomJSBridge* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_setNativeJSBridgeCallback : Invalid Native Object");
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
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_setNativeJSBridgeCallback : Error processing arguments");
        cobj->setNativeJSBridgeCallback(arg0.value());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_setNativeJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_setSdkJSBridgeCallback(se::State& s)
{
    cc::CustomJSBridge* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
    SE_PRECONDITION2(cobj, false, "js_customJSBridge_CustomJSBridge_setSdkJSBridgeCallback : Invalid Native Object");
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
        SE_PRECONDITION2(ok, false, "js_customJSBridge_CustomJSBridge_setSdkJSBridgeCallback : Error processing arguments");
        cobj->setSdkJSBridgeCallback(arg0.value());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_customJSBridge_CustomJSBridge_setSdkJSBridgeCallback)

static bool js_customJSBridge_CustomJSBridge_getInstance(se::State& s)
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



static bool js_cc_CustomJSBridge_finalize(se::State& s)
{
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(SE_THIS_OBJECT<cc::CustomJSBridge>(s));
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        cc::CustomJSBridge* cobj = SE_THIS_OBJECT<cc::CustomJSBridge>(s);
        JSB_FREE(cobj);
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cc_CustomJSBridge_finalize)

bool js_register_customJSBridge_CustomJSBridge(se::Object* obj)
{
    auto cls = se::Class::create("CustomJSBridge", obj, nullptr, nullptr);

    cls->defineFunction("callNativeJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_callNativeJSBridgeCallback));
    cls->defineFunction("callSdkJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_callSdkJSBridgeCallback));
    cls->defineFunction("clearCustomJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_clearCustomJSBridgeCallback));
    cls->defineFunction("setNativeJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_setNativeJSBridgeCallback));
    cls->defineFunction("setSdkJSBridgeCallback", _SE(js_customJSBridge_CustomJSBridge_setSdkJSBridgeCallback));
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

