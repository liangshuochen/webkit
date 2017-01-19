//
//  JSRectangle.hpp
//  JavaScriptCore
//
//  Created by liangshuochen on 14/01/2017.
//
//

#ifndef JSRectangle0_h
#define JSRectangle0_h

#include "config.h"
#include "Rectangle.h"

using namespace JSC;

class JSRectangle0 : public JSC::JSDestructibleObject {
protected:
    JSRectangle0(VM& vm, Structure* structure, JSGlobalObject* globalObject, void* data);
    JSRectangle0(ExecState*, Structure*, void* data);

//    void finishCreation(ExecState*);
    void finishCreation(VM&);

public:
    typedef JSC::JSDestructibleObject Base;
    static const unsigned StructureFlags = Base::StructureFlags | ProhibitsPropertyCaching | OverridesGetOwnPropertySlot | InterceptsGetOwnPropertySlotByIndexEvenWhenLengthIsNotZero | ImplementsHasInstance | OverridesGetPropertyNames | TypeOfShouldCallGetCallData;

    ~JSRectangle0() {}

    static JSRectangle0* create(ExecState* exec, JSGlobalObject* globalObject, Structure* structure, void* data)
    {
        ASSERT_UNUSED(globalObject, !structure->globalObject() || structure->globalObject() == globalObject);
        JSRectangle0* ptr = new (NotNull, allocateCell<JSRectangle0>(*exec->heap())) JSRectangle0(exec, structure, data);
        ptr->finishCreation(exec->vm());
        return ptr;
    }
    
    static JSRectangle0* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, void* data = NULL)
    {
        Structure* structure = createStructure(vm, globalObject, jsNull());
        JSRectangle0* ptr = new (NotNull, JSC::allocateCell<JSRectangle0>(vm.heap)) JSRectangle0(vm, structure, globalObject, data);
        ptr->finishCreation(vm);
        return ptr;
        
    }
    
    static Structure* createStructure(VM& vm, JSGlobalObject* globalObject, JSValue prototype)
    {
        return Structure::create(vm, globalObject, prototype, TypeInfo(ObjectType, StructureFlags), info());
    }


    static const bool needsDestruction;
    static void destroy(JSCell* cell)
    {
        static_cast<JSRectangle0*>(cell)->JSRectangle0::~JSRectangle0();
    }

    static Rectangle* toPrivate(JSValue value);
    void setPrivate(void* data);
    Rectangle& getPrivate() const
    {
        return static_cast<Rectangle&>(*m_privateData);
    };
    
    DECLARE_INFO;

    using Base::methodTable;
    
private:
/*
    static bool getOwnPropertySlot(JSObject*, ExecState*, PropertyName, PropertySlot&);
    static bool getOwnPropertySlotByIndex(JSObject*, ExecState*, unsigned propertyName, PropertySlot&);
    
    static bool put(JSCell*, ExecState*, PropertyName, JSValue, PutPropertySlot&);
    static bool putByIndex(JSCell*, ExecState*, unsigned, JSValue, bool shouldThrow);

    static bool deleteProperty(JSCell*, ExecState*, PropertyName);
    static bool deletePropertyByIndex(JSCell*, ExecState*, unsigned);

    static bool customHasInstance(JSObject*, ExecState*, JSValue);

    static void getOwnNonIndexPropertyNames(JSObject*, ExecState*, PropertyNameArray&, EnumerationMode);

    static ConstructType getConstructData(JSCell*, ConstructData&);
    static CallType getCallData(JSCell*, CallData&);

    static void visitChildren(JSCell* cell, SlotVisitor& visitor)
    {
        auto* thisObject = jsCast<JSRectangle0*>(cell);
        ASSERT_GC_OBJECT_INHERITS(thisObject, info());
        Base::visitChildren(thisObject, visitor);
        thisObject->visitAdditionalChildren(visitor);
    }

    void init(ExecState*);
 
//    static JSRectangle0* asCallbackObject(JSValue);
//    static JSRectangle0* asCallbackObject(EncodedJSValue);
 
//    static EncodedJSValue JSC_HOST_CALL call(ExecState*);
//    static EncodedJSValue JSC_HOST_CALL construct(ExecState*);
   
    JSValue getStaticValue(ExecState*, PropertyName);
    static EncodedJSValue staticFunctionGetter(ExecState*, EncodedJSValue, PropertyName);
    static EncodedJSValue callbackGetter(ExecState*, EncodedJSValue, PropertyName);
*/
    WTF::RefPtr<Rectangle> m_privateData;
};
#endif /* JSRectangle0_h */
