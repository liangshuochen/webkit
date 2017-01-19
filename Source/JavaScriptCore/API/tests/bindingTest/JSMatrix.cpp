//
//  JSMatrix.c
//  JavaScriptCore
//
//  Created by liangshuochen on 14/01/2017.
//
//

#include <wtf/Platform.h>
#include <wtf/Assertions.h>


#include "JSObjectRef.h"
#include "JSStringRef.h"
#include "JSValueRef.h"
#include "JSMatrix.h"
#include "Matrix.h"
#include "Rectangle.h"

#define EGRET_Matrix "egretMatrix"
#define GET_CPP_THIZ_OBJCET(X) \
Matrix *cppThiz = (Matrix*) JSObjectGetPrivate(X); \
if (!cppThiz) { \
printf("JSMatrix %s: cppThiz is lost", __func__); \
return NULL; \
}

#define GET_CPP_THIZ_OBJCET_FINALIZE(X) \
Matrix *cppThiz = (Matrix*) JSObjectGetPrivate(X); \
if (!cppThiz) { \
printf("JSMatrix %s: cppThiz in finalize is lost", __func__); \
return; \
}


static JSValueRef JSMatrix_setTo(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    
    UNUSED_PARAM(function);
    if (argumentCount < 6) {
        printf("JSMatrix %s bad arguments, %zu < expected %d", __func__, argumentCount, 6);
        return JSValueMakeUndefined(context);
    }
    
    GET_CPP_THIZ_OBJCET(thisObject);
    
	float cArg0 = JSValueToNumber(context, arguments[0], exception);
	float cArg1 = JSValueToNumber(context, arguments[1], exception);
	float cArg2 = JSValueToNumber(context, arguments[2], exception);
	float cArg3 = JSValueToNumber(context, arguments[3], exception);
	float cArg4 = JSValueToNumber(context, arguments[4], exception);
	float cArg5 = JSValueToNumber(context, arguments[5], exception);
    
    cppThiz->setTo(cArg0, cArg1, cArg2, cArg3, cArg4, cArg5);
    
    return JSValueMakeUndefined(context);
}

static JSValueRef JSMatrix_transformBounds(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UNUSED_PARAM(function);
    if (argumentCount < 1) {
        printf("JSMatrix %s bad arguments, %zu < expected %d", __func__, argumentCount, 1);
        return JSValueMakeUndefined(context);
    }
    
    GET_CPP_THIZ_OBJCET(thisObject);
    
    Rectangle* rec = (Rectangle*)JSObjectGetPrivate(JSValueToObject(context, arguments[0], exception));
    
    cppThiz->transformBounds(rec);
    
    return JSValueMakeUndefined(context);
}

static JSValueRef JSMatrix_transformBoundsNoField(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UNUSED_PARAM(function);
    if (argumentCount < 4) {
        printf("JSMatrix %s bad arguments, %zu < expected %d", __func__, argumentCount, 4);
        return JSValueMakeUndefined(context);
    }
    
    GET_CPP_THIZ_OBJCET(thisObject);
    
	float cArg0 = JSValueToNumber(context, arguments[0], exception);
	float cArg1 = JSValueToNumber(context, arguments[1], exception);
	float cArg2 = JSValueToNumber(context, arguments[2], exception);
	float cArg3 = JSValueToNumber(context, arguments[3], exception);
   
    cppThiz->transformBoundsNoField(cArg0, cArg1, cArg2, cArg3);
    
    return JSValueMakeUndefined(context);
    
}

static JSValueRef JSMatrix_toString(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UNUSED_PARAM(function);
    UNUSED_PARAM(exception);
    UNUSED_PARAM(argumentCount);
    UNUSED_PARAM(arguments);
    
    GET_CPP_THIZ_OBJCET(thisObject);
    
    JSStringRef retStr = JSStringCreateWithUTF8CString(cppThiz->toString().utf8().data());
    return JSValueMakeString(context, retStr);
}


static JSValueRef JSMatrix_getter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef *ex)
{
    UNUSED_PARAM(ex);
    GET_CPP_THIZ_OBJCET(object);
    if (JSStringIsEqualToUTF8CString(propertyName, "a")) {
        return JSValueMakeNumber(ctx, cppThiz->a);
    } else if (JSStringIsEqualToUTF8CString(propertyName, "b")) {
        return JSValueMakeNumber(ctx, cppThiz->b);
    } else if (JSStringIsEqualToUTF8CString(propertyName, "c")) {
        return JSValueMakeNumber(ctx, cppThiz->c);
    } else if (JSStringIsEqualToUTF8CString(propertyName, "d")) {
        return JSValueMakeNumber(ctx, cppThiz->d);
    } else if (JSStringIsEqualToUTF8CString(propertyName, "tx")) {
        return JSValueMakeNumber(ctx, cppThiz->tx);
    } else if (JSStringIsEqualToUTF8CString(propertyName, "ty")) {
        return JSValueMakeNumber(ctx, cppThiz->ty);
    }
    return JSValueMakeUndefined(ctx);
}

static bool JSMatrix_setter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSValueRef *ex)
{
    UNUSED_PARAM(ex);
    Matrix* cppThiz = (Matrix*)JSObjectGetPrivate(object);
    if(!cppThiz)
    {
        return false;
    }
    
    if (JSStringIsEqualToUTF8CString(propertyName, "a")) {
        cppThiz->a = (JSValueToNumber(ctx, value, NULL));
    } else if (JSStringIsEqualToUTF8CString(propertyName, "b")) {
        cppThiz->b = (JSValueToNumber(ctx, value, NULL));
    } else if (JSStringIsEqualToUTF8CString(propertyName, "c")) {
        cppThiz->c = (JSValueToNumber(ctx, value, NULL));
    } else if (JSStringIsEqualToUTF8CString(propertyName, "d")) {
        cppThiz->d = (JSValueToNumber(ctx, value, NULL));
    } else if (JSStringIsEqualToUTF8CString(propertyName, "tx")) {
        cppThiz->tx = (JSValueToNumber(ctx, value, NULL));
    } else if (JSStringIsEqualToUTF8CString(propertyName, "ty")) {
        cppThiz->ty = (JSValueToNumber(ctx, value, NULL));
    }
    
    return true;
}

static JSStaticValue JSMatrix_staticValues[] = {
    {"a", JSMatrix_getter, JSMatrix_setter, kJSPropertyAttributeDontDelete},
    {"b", JSMatrix_getter, JSMatrix_setter, kJSPropertyAttributeDontDelete},
    {"c", JSMatrix_getter, JSMatrix_setter, kJSPropertyAttributeDontDelete},
    {"d", JSMatrix_getter, JSMatrix_setter, kJSPropertyAttributeDontDelete},
    {"tx", JSMatrix_getter, JSMatrix_setter, kJSPropertyAttributeDontDelete},
    {"ty", JSMatrix_getter, JSMatrix_setter, kJSPropertyAttributeDontDelete},
    {0, 0, 0, 0},
};

static JSStaticFunction JSMatrix_staticFunctions[] = {
    { "setTo", JSMatrix_setTo, kJSPropertyAttributeDontDelete },
    { "toString", JSMatrix_toString, kJSPropertyAttributeDontDelete },
    { "transformBounds", JSMatrix_transformBounds, kJSPropertyAttributeDontDelete },
    { "transformBoundsNoField", JSMatrix_transformBoundsNoField, kJSPropertyAttributeDontDelete },

    {0, 0, 0 }
};

static JSObjectRef JSMatrix_constructor(JSContextRef context, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UNUSED_PARAM(constructor);
    UNUSED_PARAM(argumentCount);
    UNUSED_PARAM(exception);
    
	float cArg0 = JSValueToNumber(context, arguments[0], exception);
	float cArg1 = JSValueToNumber(context, arguments[1], exception);
	float cArg2 = JSValueToNumber(context, arguments[2], exception);
	float cArg3 = JSValueToNumber(context, arguments[3], exception);
	float cArg4 = JSValueToNumber(context, arguments[4], exception);
	float cArg5 = JSValueToNumber(context, arguments[5], exception);
    Matrix *matrix = new Matrix(cArg0, cArg1, cArg2, cArg3, cArg4, cArg5);
    
    return JSObjectMake(context, JSMatrix_class(context), matrix);
}

static void JSMatrix_finalize(JSObjectRef object)
{
//    GET_CPP_THIZ_OBJCET_FINALIZE(object);
    Matrix *cppThiz = (Matrix*) JSObjectGetPrivate(object);
    if (!cppThiz) {
//        printf("JSMatrix %s: cppThiz in finalize is lost", __func__);
        return;
    }
}

extern JSObjectRef JSMatrix_new(JSContextRef context, Matrix* node)
{
    return JSObjectMake(context, JSMatrix_class(context), node);
}

extern JSClassRef JSMatrix_class(JSContextRef context)
{
    UNUSED_PARAM(context);

    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.staticValues = JSMatrix_staticValues;
        definition.staticFunctions = JSMatrix_staticFunctions;
        definition.callAsConstructor = JSMatrix_constructor;
        definition.finalize = JSMatrix_finalize;

        jsClass = JSClassCreate(&definition);
    }
    return jsClass;
}

extern void setMatrixIn(JSContextRef ctx, JSObjectRef parent, const char *name, JSClassRef jsClass)
{
    JSObjectRef jsObject = JSObjectMake(ctx, jsClass, NULL);
    JSStringRef className = JSStringCreateWithUTF8CString(name);
    JSValueRef ex = NULL;
    JSObjectSetProperty(ctx, parent, className, jsObject, kJSPropertyAttributeNone, &ex);
    JSStringRelease(className);
}
