//
//  JSRectangle.c
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
#include "JSTypedArray.h"
#include "JSRectangle.h"
#include "Matrix.h"
#include "Rectangle.h"

#define EGRET_RECTANGLE "egretRectangle"
#define GET_CPP_THIZ_OBJCET(X) \
Rectangle* cppThiz = (Rectangle*) JSObjectGetPrivate(X); \
if (!cppThiz) { \
printf("JSRectangle %s: cppThiz is lost", __func__); \
return NULL; \
}

#define GET_CPP_THIZ_OBJCET_FINALIZE(X) \
Rectangle* cppThiz = (Rectangle*) JSObjectGetPrivate(X); \
if (!cppThiz) { \
printf("JSRectangle %s: cppThiz in finalize is lost", __func__); \
return; \
}


static JSValueRef JSRectangle_setTo(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    
    UNUSED_PARAM(function);
    if (argumentCount < 4) {
        printf("JSRectangle %s bad arguments, %zu < expected %d", __func__, argumentCount, 4);
        return JSValueMakeUndefined(context);
    }
    
    GET_CPP_THIZ_OBJCET(thisObject);
    
    float cArg0 = JSValueToNumber(context, arguments[0], exception);
    float cArg1 = JSValueToNumber(context, arguments[1], exception);
    float cArg2 = JSValueToNumber(context, arguments[2], exception);
    float cArg3 = JSValueToNumber(context, arguments[3], exception);
    
    cppThiz->setTo(cArg0, cArg1, cArg2, cArg3);
    
    return JSValueMakeUndefined(context);
}

static JSValueRef JSRectangle_setToAsTypedArray(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    
    UNUSED_PARAM(function);
    if (argumentCount < 1) {
        printf("JSRectangle %s bad arguments, %zu < expected %d", __func__, argumentCount, 4);
        return JSValueMakeUndefined(context);
    }
    
    GET_CPP_THIZ_OBJCET(thisObject);
    
    JSObjectRef object = JSValueToObject(context, arguments[0], NULL);
    int16_t* dataptr = (int16_t*)JSObjectGetTypedArrayBytesPtr(context, object, exception);
    int i = 0;
    float arg[4] = {0};
    while(i<5)
    {
        arg[i] = *dataptr;
        dataptr++;
        i++;
    }
    cppThiz->setTo(arg[0],arg[1],arg[2],arg[3]);
    
    return JSValueMakeUndefined(context);
}

static JSValueRef JSRectangle_toString(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UNUSED_PARAM(function);
    UNUSED_PARAM(exception);
    UNUSED_PARAM(argumentCount);
    UNUSED_PARAM(arguments);
    
    GET_CPP_THIZ_OBJCET(thisObject);
    
    JSStringRef retStr = JSStringCreateWithUTF8CString(cppThiz->toString().utf8().data());
    return JSValueMakeString(context, retStr);
}
static JSStaticFunction JSRectangle_staticFunctions[] = {
    { "setTo", JSRectangle_setTo, kJSPropertyAttributeDontDelete },
    { "setToAsTypedArray", JSRectangle_setToAsTypedArray, kJSPropertyAttributeDontDelete },
    { "toString", JSRectangle_toString, kJSPropertyAttributeDontDelete },
    {0, 0, 0 }
};

static JSValueRef JSRectangle_getter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef *ex)
{
    UNUSED_PARAM(ex);
    GET_CPP_THIZ_OBJCET(object);
    if (JSStringIsEqualToUTF8CString(propertyName, "x")) {
        return JSValueMakeNumber(ctx, cppThiz->x);
    } else if (JSStringIsEqualToUTF8CString(propertyName, "y")) {
        return JSValueMakeNumber(ctx, cppThiz->y);
    } else if (JSStringIsEqualToUTF8CString(propertyName, "width")) {
        return JSValueMakeNumber(ctx, cppThiz->width);
    } else if (JSStringIsEqualToUTF8CString(propertyName, "height")) {
        return JSValueMakeNumber(ctx, cppThiz->height);
    }
    return JSValueMakeUndefined(ctx);
}

static bool JSRectangle_setter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSValueRef *ex)
{
    UNUSED_PARAM(ex);
    Rectangle* cppThiz = (Rectangle*)JSObjectGetPrivate(object);
    if(!cppThiz)
    {
        return false;
    }
    
    if (JSStringIsEqualToUTF8CString(propertyName, "x")) {
        cppThiz->x = (JSValueToNumber(ctx, value, NULL));
    } else if (JSStringIsEqualToUTF8CString(propertyName, "y")) {
        cppThiz->y = (JSValueToNumber(ctx, value, NULL));
    } else if (JSStringIsEqualToUTF8CString(propertyName, "width")) {
        cppThiz->width = (JSValueToNumber(ctx, value, NULL));
    } else if (JSStringIsEqualToUTF8CString(propertyName, "height")) {
        cppThiz->height = (JSValueToNumber(ctx, value, NULL));
    }
    
    return true;
}

static JSStaticValue JSRectangle_staticValues[] = {
    {"x", JSRectangle_getter, JSRectangle_setter, kJSPropertyAttributeDontDelete},
    {"y", JSRectangle_getter, JSRectangle_setter, kJSPropertyAttributeDontDelete},
    {"width", JSRectangle_getter, JSRectangle_setter, kJSPropertyAttributeDontDelete},
    {"height", JSRectangle_getter, JSRectangle_setter, kJSPropertyAttributeDontDelete},
    {0, 0, 0, 0},
};

static JSObjectRef JSRectangle_constructor(JSContextRef context, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UNUSED_PARAM(constructor);
    UNUSED_PARAM(argumentCount);
    UNUSED_PARAM(exception);
    
	float cArg0 = JSValueToNumber(context, arguments[0], exception);
	float cArg1 = JSValueToNumber(context, arguments[1], exception);
	float cArg2 = JSValueToNumber(context, arguments[2], exception);
	float cArg3 = JSValueToNumber(context, arguments[3], exception);
    Rectangle* rectangle = new Rectangle(cArg0, cArg1, cArg2, cArg3);
    
    JSObjectRef test = JSObjectMake(context, JSRectangle_class(context), rectangle);
    return test;
}
static void JSRectangle_finalize(JSObjectRef object)
{
//    GET_CPP_THIZ_OBJCET_FINALIZE(object);
    
    Rectangle* cppThiz = (Rectangle*) JSObjectGetPrivate(object);
    if (!cppThiz) {
//        printf("JSRectangle %s: cppThiz in finalize is lost", __func__);
    }
}

extern JSObjectRef JSRectangle_new(JSContextRef context, Rectangle* node)
{
    return JSObjectMake(context, JSRectangle_class(context), node);
}

extern JSClassRef JSRectangle_class(JSContextRef context)
{
    UNUSED_PARAM(context);
    
    static JSClassRef jsClass;
    if (!jsClass) {
        JSClassDefinition definition = kJSClassDefinitionEmpty;
        definition.className = EGRET_RECTANGLE;
        definition.staticFunctions = JSRectangle_staticFunctions;
        definition.staticValues = JSRectangle_staticValues;
        definition.callAsConstructor = JSRectangle_constructor;
        definition.finalize = JSRectangle_finalize;
        
        jsClass = JSClassCreate(&definition);
    }
    return jsClass;
}

extern void setRectangleIn(JSContextRef ctx, JSObjectRef parent, const char *name, JSClassRef jsClass)
{
    JSObjectRef jsObject = JSObjectMake(ctx, jsClass, NULL);
    JSStringRef className = JSStringCreateWithUTF8CString(name);
    JSValueRef ex = NULL;
    JSObjectSetProperty(ctx, parent, className, jsObject, kJSPropertyAttributeNone, &ex);
    JSStringRelease(className);
}
