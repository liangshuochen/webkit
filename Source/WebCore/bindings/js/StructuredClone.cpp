/*
 * Copyright (C) 2016 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "config.h"
#include "StructuredClone.h"

#include "JSDOMBinding.h"
#include <runtime/JSTypedArrays.h>

using namespace JSC;

namespace WebCore {

EncodedJSValue JSC_HOST_CALL structuredCloneArrayBuffer(ExecState* state)
{
    ASSERT(state);
    ASSERT(state->argumentCount());
    ASSERT(state->lexicalGlobalObject());

    auto* buffer = toUnsharedArrayBuffer(state->uncheckedArgument(0));
    if (!buffer) {
        VM& vm = state->vm();
        auto scope = DECLARE_THROW_SCOPE(vm);
        throwDataCloneError(*state, scope);
        return { };
    }
    return JSValue::encode(JSArrayBuffer::create(state->vm(), state->lexicalGlobalObject()->arrayBufferStructure(ArrayBufferSharingMode::Default), ArrayBuffer::tryCreate(buffer->data(), buffer->byteLength())));
}

EncodedJSValue JSC_HOST_CALL structuredCloneArrayBufferView(ExecState* state)
{
    ASSERT(state);
    ASSERT(state->argumentCount());

    JSValue value = state->uncheckedArgument(0);
    auto* bufferView = jsDynamicDowncast<JSArrayBufferView*>(value);
    ASSERT(bufferView);

    auto* buffer = bufferView->unsharedBuffer();
    if (!buffer) {
        VM& vm = state->vm();
        auto scope = DECLARE_THROW_SCOPE(vm);
        throwDataCloneError(*state, scope);
        return { };
    }
    auto bufferClone = ArrayBuffer::tryCreate(buffer->data(), buffer->byteLength());

    if (jsDynamicDowncast<JSInt8Array*>(value))
        return JSValue::encode(JSInt8Array::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSInt16Array*>(value))
        return JSValue::encode(JSInt16Array::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSInt32Array*>(value))
        return JSValue::encode(JSInt32Array::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSUint8Array*>(value))
        return JSValue::encode(JSUint8Array::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSUint8ClampedArray*>(value))
        return JSValue::encode(JSUint8ClampedArray::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSUint16Array*>(value))
        return JSValue::encode(JSUint16Array::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSUint32Array*>(value))
        return JSValue::encode(JSUint32Array::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSFloat32Array*>(value))
        return JSValue::encode(JSFloat32Array::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSFloat64Array*>(value))
        return JSValue::encode(JSFloat64Array::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));
    if (jsDynamicDowncast<JSDataView*>(value))
        return JSValue::encode(JSDataView::create(state, bufferView->structure(), WTFMove(bufferClone), bufferView->byteOffset(), bufferView->length()));

    ASSERT_NOT_REACHED();
    return JSValue::encode(jsUndefined());
}

} // namespace WebCore
