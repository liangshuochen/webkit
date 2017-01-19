//
//  JSMatrix0.cpp
//  JavaScriptCore
//
//  Created by liangshuochen on 15/01/2017.
//
//

#include "config.h"
#include "ClassInfo.h"
#include "Lookup.h"
#include "Error.h"
#include "JSCJSValueInlines.h"
#include "JSArray.h"
#include "JSString.h"
#include "JSCell.h"
#include "JSCellInlines.h"
#include "HeapInlines.h"
#include "JSObject.h"
#include "JSObjectInlines.h"
#include "Structure.h"
#include "StructureInlines.h"
#include "JSTypedArray.h"
#include "TypedArrayType.h"
#include "JSArrayBufferViewInlines.h"

#include <wtf/GetPtr.h>
#include <wtf/Platform.h>
#include <wtf/Variant.h>

#include "JSMatrix0.h"
#include "JSRectangle0.h"
#include "Matrix.h"
#include "Rectangle.h"

using namespace JSC;

JSC::EncodedJSValue JSC_HOST_CALL jsMatrix0PrototypeFunctionSetTo(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsMatrix0PrototypeFunctionSetToTypedArray(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsMatrix0PrototypeFunctionTransformBounds(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsMatrix0PrototypeFunctionToString(JSC::ExecState*);

// Attributes
JSC::EncodedJSValue jsMatrix0A(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsMatrix0B(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsMatrix0C(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsMatrix0D(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsMatrix0Tx(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsMatrix0Ty(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSMatrix0Constructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);


const bool JSMatrix0::needsDestruction = true;
static const HashTableValue JSMatrix0PrototypeTableValues[] =
{
    { "a", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsMatrix0A), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "b", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsMatrix0B), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "c", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsMatrix0C), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "d", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsMatrix0D), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "tx", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsMatrix0Tx), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "ty", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsMatrix0Ty), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    
    { "setTo", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsMatrix0PrototypeFunctionSetTo), (intptr_t) (6) } },
    { "setToAsTypedArray", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsMatrix0PrototypeFunctionSetToTypedArray), (intptr_t) (6) } },
    
    { "transformBounds", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsMatrix0PrototypeFunctionTransformBounds), (intptr_t) (1) } },
    
    { "toString", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsMatrix0PrototypeFunctionToString), (intptr_t) (0) } },
};



const ClassInfo JSMatrix0::s_info = { "Matrix0", &Base::s_info, 0, CREATE_METHOD_TABLE(JSMatrix0) };

JSMatrix0::JSMatrix0(VM& vm, Structure* structure, JSGlobalObject* globalObject, void* data)
: JSDestructibleObject(vm, structure)
, m_privateData((Matrix*)(data))
{
    ASSERT_UNUSED(globalObject, globalObject);
}

JSMatrix0::JSMatrix0(ExecState* exec, Structure* structure, void* data)
: Base(exec->vm(), structure)
, m_privateData((Matrix*)(data))
{
}


void JSMatrix0::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSMatrix0PrototypeTableValues, *this);
}

void JSMatrix0::setPrivate(void *data)
{
    if(m_privateData != data)
    {
        m_privateData = static_cast<Matrix*>(data);
    }
}

bool setJSMatrix0Constructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    UNUSED_PARAM(state);
    UNUSED_PARAM(thisValue);
    UNUSED_PARAM(encodedValue);
//    JSValue value = JSValue::decode(encodedValue);
//    JSMatrix0Prototype* domObject = jsDynamicCast<JSMatrix0Prototype*>(JSValue::decode(thisValue));
//    if (UNLIKELY(!domObject)) {
//        throwVMTypeError(state);
//        return false;
//    }
//    // Shadowing a built-in constructor
//    return domObject->putDirect(state->vm(), state->propertyNames().constructor, value);
    return false;
}

EncodedJSValue JSC_HOST_CALL jsMatrix0PrototypeFunctionSetTo(ExecState* state)
{
    JSValue thisValue = state->thisValue();
    auto castedThis = jsDynamicCast<JSMatrix0*>(thisValue);
    if (UNLIKELY(!castedThis))
        return JSValue::encode(jsUndefined());
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSMatrix0::info());
    auto& impl = castedThis->getPrivate();
    if (UNLIKELY(state->argumentCount() < 6))
    {
        return JSValue::encode(jsUndefined());
    }
    auto arg0 = state->argument(0).toNumber(state);
    auto arg1 = state->argument(1).toNumber(state);
    auto arg2 = state->argument(2).toNumber(state);
    auto arg3 = state->argument(3).toNumber(state);
    auto arg4 = state->argument(4).toNumber(state);
    auto arg5 = state->argument(5).toNumber(state);
//    if (UNLIKELY(state->hadException()))
//        return JSValue::encode(jsUndefined());
    impl.setTo(WTFMove(arg0),WTFMove(arg1),WTFMove(arg2),WTFMove(arg3),WTFMove(arg4),WTFMove(arg5));
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsMatrix0PrototypeFunctionSetToTypedArray(ExecState* state)
{
    JSValue thisValue = state->thisValue();
    auto castedThis = jsDynamicCast<JSMatrix0*>(thisValue);
    if (UNLIKELY(!castedThis))
        return JSValue::encode(jsUndefined());
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSMatrix0::info());
    auto& impl = castedThis->getPrivate();
    if (UNLIKELY(state->argumentCount() < 6))
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
        float arg[6] = {0};
        while(i<7)
        {
            arg[i] = *dataptr;
            dataptr++;
        }
        impl.setTo(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5]);
    }

    //    if (UNLIKELY(state->hadException()))
    //        return JSValue::encode(jsUndefined());
    return JSValue::encode(jsUndefined());
}


JSC::EncodedJSValue JSC_HOST_CALL jsMatrix0PrototypeFunctionTransformBounds(JSC::ExecState* state)
{
    JSValue thisValue = state->thisValue();
    auto castedThis = jsDynamicCast<JSMatrix0*>(thisValue);
    if (UNLIKELY(!castedThis))
        return JSValue::encode(jsUndefined());
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSMatrix0::info());
    auto& impl = castedThis->getPrivate();
    if (UNLIKELY(state->argumentCount() < 1))
        return JSValue::encode(jsUndefined());
    Rectangle* rectangle = nullptr;
    if (!state->argument(0).isUndefinedOrNull()) {
        rectangle = JSRectangle0::toPrivate(state->uncheckedArgument(0));
        if (UNLIKELY(!rectangle ))
            return JSValue::encode(jsUndefined());
        impl.transformBounds(rectangle);
    }
    return JSValue::encode(jsUndefined());

}

JSC::EncodedJSValue JSC_HOST_CALL jsMatrix0PrototypeFunctionToString(JSC::ExecState* state)
{
    JSValue thisValue = state->thisValue();
    auto castedThis = jsDynamicCast<JSMatrix0*>(thisValue);
    if (UNLIKELY(!castedThis))
        return JSValue::encode(jsUndefined());
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSMatrix0::info());
    auto& impl = castedThis->getPrivate();
    if (UNLIKELY(state->argumentCount() < 1))
        return JSValue::encode(jsUndefined());
    JSValue result = jsString(state, impl.toString());
    return JSValue::encode(result);
}


JSC::EncodedJSValue jsMatrix0A(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSMatrix0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber(impl.a);
    return JSValue::encode(result);
}

JSC::EncodedJSValue jsMatrix0B(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSMatrix0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber(impl.b);
    return JSValue::encode(result);
}

JSC::EncodedJSValue jsMatrix0C(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSMatrix0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber(impl.c);
    return JSValue::encode(result);
}

JSC::EncodedJSValue jsMatrix0D(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSMatrix0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber(impl.d);
    return JSValue::encode(result);
}

JSC::EncodedJSValue jsMatrix0Tx(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSMatrix0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber(impl.tx);
    return JSValue::encode(result);
}

JSC::EncodedJSValue jsMatrix0Ty(JSC::ExecState* state, JSC::EncodedJSValue thisValue, JSC::PropertyName)
{
    UNUSED_PARAM(state);
    JSValue decodedThisValue = JSValue::decode(thisValue);
    auto* castedThis = jsDynamicCast<JSMatrix0*>(decodedThisValue);
    if (UNLIKELY(!castedThis)) {
        return JSValue::encode(jsUndefined());
    }
    auto& impl = castedThis->getPrivate();
    JSValue result = jsNumber(impl.ty);
    return JSValue::encode(result);
}
