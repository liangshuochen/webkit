//
//  JSRectangle.c
//  JavaScriptCore
//
//  Created by liang on 17/1/16.
//
//

#include "config.h"
#include "ClassInfo.h"
#include "Lookup.h"
#include "Error.h"
#include "JSArray.h"
#include "JSCJSValueInlines.h"
#include "HeapInlines.h"
#include "JSObjectInlines.h"
#include "Structure.h"
#include "StructureInlines.h"

#include <wtf/GetPtr.h>
#include <wtf/Platform.h>
#include <wtf/Variant.h>

#include "JSRectangle0.h"

using namespace JSC;

JSC::EncodedJSValue JSC_HOST_CALL jsRectangle0PrototypeFunctionSetTo(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsRectangle0PrototypeFunctionSetToTypedArray(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsRectangle0PrototypeFunctionTransformBounds(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsRectangle0PrototypeFunctionToString(JSC::ExecState*);

// Attributes
JSC::EncodedJSValue jsRectangle0X(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName);
JSC::EncodedJSValue jsRectangle0Y(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName);
JSC::EncodedJSValue jsRectangle0Width(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName);
JSC::EncodedJSValue jsRectangle0Height(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName);
bool setJSRectangle0PrototypeConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);


const bool JSRectangle0::needsDestruction = true;
static const HashTableValue JSRectangle0PrototypeTableValues[] =
{
    { "x", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsRectangle0X), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "y", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsRectangle0Y), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "width", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsRectangle0Width), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "height", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsRectangle0Height), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    
    { "setTo", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsRectangle0PrototypeFunctionSetTo), (intptr_t) (6) } },
    { "setToAsTypedArray", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsRectangle0PrototypeFunctionSetToTypedArray), (intptr_t) (6) } },
    
    { "toString", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsRectangle0PrototypeFunctionToString), (intptr_t) (0) } },
};



const ClassInfo JSRectangle0::s_info = { "Rectangle0", &Base::s_info, 0, CREATE_METHOD_TABLE(JSRectangle0) };

JSRectangle0::JSRectangle0(VM& vm, Structure* structure, JSGlobalObject* globalObject, void* data)
: JSDestructibleObject(vm, structure)
, m_privateData((Rectangle*)(data))
{
    ASSERT_UNUSED(globalObject, globalObject);
}

JSRectangle0::JSRectangle0(ExecState* exec, Structure* structure, void* data)
: Base(exec->vm(), structure)
, m_privateData((Rectangle*)(data))
{
}


void JSRectangle0::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSRectangle0PrototypeTableValues, *this);
}

Rectangle* JSRectangle0::toPrivate(JSValue value)
{
    JSRectangle0* jsobject = nullptr;
    if (!value.isObject())
        return 0;
    while (!value.isNull()) {
        JSObject* object = asObject(value);
        const ClassInfo* classInfo = object->classInfo();
        if (classInfo == JSRectangle0::info())
            jsobject = jsCast<JSRectangle0*>(object);
        if (jsobject == nullptr)
            return 0;
        return &(jsobject->getPrivate());
        value = object->getPrototypeDirect();
    }
    return 0;
}

void JSRectangle0::setPrivate(void *data)
{
    if(m_privateData != data)
    {
        m_privateData = static_cast<Rectangle*>(data);
    }
}

bool setJSRectangle0PrototypeConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    UNUSED_PARAM(state);
    UNUSED_PARAM(thisValue);
    UNUSED_PARAM(encodedValue);

//    JSValue value = JSValue::decode(encodedValue);
//    JSRectangle0Prototype* domObject = jsDynamicCast<JSRectangle0Prototype*>(JSValue::decode(thisValue));
//    if (UNLIKELY(!domObject)) {
//        throwVMTypeError(state);
//        return false;
//    }
//    // Shadowing a built-in constructor
//    return domObject->putDirect(state->vm(), state->propertyNames().constructor, value);
    return false;
}

EncodedJSValue JSC_HOST_CALL jsRectangle0PrototypeFunctionSetTo(ExecState* state)
{
    JSValue thisValue = state->thisValue();
    auto castedThis = jsDynamicCast<JSRectangle0*>(thisValue);
    if (UNLIKELY(!castedThis))
        return JSValue::encode(jsUndefined());
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSRectangle0::info());
    auto& impl = castedThis->getPrivate();
    if (UNLIKELY(state->argumentCount() < 4))
        return JSValue::encode(jsUndefined());
    auto arg0 = state->argument(0).toNumber(state);
    auto arg1 = state->argument(1).toNumber(state);
    auto arg2 = state->argument(2).toNumber(state);
    auto arg3 = state->argument(3).toNumber(state);
//    if (UNLIKELY(state->hadException()))
//        return JSValue::encode(jsUndefined());
    impl.setTo(WTFMove(arg0),WTFMove(arg1),WTFMove(arg2),WTFMove(arg3));
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsRectangle0PrototypeFunctionSetToTypedArray(ExecState* state)
{
    JSValue thisValue = state->thisValue();
    auto castedThis = jsDynamicCast<JSRectangle0*>(thisValue);
    if (UNLIKELY(!castedThis))
        return JSValue::encode(jsUndefined());
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSRectangle0::info());
    auto& impl = castedThis->getPrivate();
    if (UNLIKELY(state->argumentCount() < 1))
    {
        return JSValue::encode(jsUndefined());
    }
    
    auto arg0 = state->argument(0).toObject(state);
//    if (JSArrayBuffer* jsBuffer = jsDynamicCast<JSArrayBuffer*>(arg0))
//    {
//        ArrayBuffer* buffer = jsBuffer->impl();
//        buffer->pinAndLock();
//        void* dataptr = buffer->data();
//    }
    if (JSArrayBufferView* typedArray = jsDynamicCast<JSArrayBufferView*>(arg0))
    {
//        unsigned len = typedArray->length();
//        size_t eleSize = JSC::elementSize(arg0->classInfo()->typedArrayStorageType);
        ArrayBuffer* buffer = typedArray->possiblySharedBuffer();
//        buffer->pinAndLock();
        int16_t* dataptr = (int16_t*)buffer->data();
        int i = 0;
        float arg[4] = {0};
        while(i<5)
        {
            arg[i] = *dataptr;
            dataptr++;
            i++;
        }
        impl.setTo(arg[0],arg[1],arg[2],arg[3]);
    }

    //    if (UNLIKELY(state->hadException()))
    //        return JSValue::encode(jsUndefined());
    return JSValue::encode(jsUndefined());
}

JSC::EncodedJSValue JSC_HOST_CALL jsRectangle0PrototypeFunctionToString(JSC::ExecState* state)
{
    
    JSValue thisValue = state->thisValue();
    auto castedThis = jsDynamicCast<JSRectangle0*>(thisValue);
    if (UNLIKELY(!castedThis))
        return JSValue::encode(jsUndefined());
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSRectangle0::info());
    auto& impl = castedThis->getPrivate();
    if (UNLIKELY(state->argumentCount() < 1))
        return JSValue::encode(jsUndefined());
    JSValue result = jsString(state, impl.toString());
    return JSValue::encode(result);
}


JSC::EncodedJSValue jsRectangle0X(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    UNUSED_PARAM(thisValue);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSRectangle0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber((double)impl.x);
    return JSValue::encode(result);
}

JSC::EncodedJSValue jsRectangle0Y(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSRectangle0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber((double)impl.y);
    return JSValue::encode(result);
}

JSC::EncodedJSValue jsRectangle0Width(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSRectangle0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber((double)impl.width);
    return JSValue::encode(result);
}

JSC::EncodedJSValue jsRectangle0Height(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    UNUSED_PARAM(thisValue);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSRectangle0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber((double)impl.height);
    return JSValue::encode(result);
}

