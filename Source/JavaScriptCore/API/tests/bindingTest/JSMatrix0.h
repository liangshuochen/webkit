//
//  JSMatrix0.h
//  JavaScriptCore
//
//  Created by liangshuochen on 15/01/2017.
//
//

#ifndef JSMatrix0_h
#define JSMatrix0_h

#include "config.h"
#include "JSGlobalObject.h"
#include "JSDestructibleObject.h"
#include "JSCell.h"
#include "JSCellInlines.h"

#include "Matrix.h"

#include <stdio.h>
using namespace JSC;

class JSMatrix0 : public JSC::JSDestructibleObject {
protected:
    JSMatrix0(VM& vm, Structure* structure, JSGlobalObject* globalObject, void* data);
    JSMatrix0(ExecState*, Structure*, void* data);
//    JSMatrix0(VM&, JSGlobalObject*, Structure*);

//    void finishCreation(ExecState*);
    void finishCreation(VM&);

public:
    typedef JSC::JSDestructibleObject Base;
    static const unsigned StructureFlags = Base::StructureFlags | ProhibitsPropertyCaching | OverridesGetOwnPropertySlot | InterceptsGetOwnPropertySlotByIndexEvenWhenLengthIsNotZero | ImplementsHasInstance | OverridesGetPropertyNames | TypeOfShouldCallGetCallData;

    ~JSMatrix0(){}

    static JSMatrix0* create(ExecState* exec, JSGlobalObject* globalObject, Structure* structure, void* data)
    {
        ASSERT_UNUSED(globalObject, !structure->globalObject() || structure->globalObject() == globalObject);
        JSMatrix0* ptr = new (NotNull, allocateCell<JSMatrix0>(*exec->heap())) JSMatrix0(exec, structure, data);
        ptr->finishCreation(exec->vm());
        return ptr;
    }
    
    static JSMatrix0* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, void* data)
    {
        Structure* structure = createStructure(vm, globalObject, jsNull());
        JSMatrix0* ptr = new (NotNull, JSC::allocateCell<JSMatrix0>(vm.heap)) JSMatrix0(vm, structure, globalObject, data);
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
        static_cast<JSMatrix0*>(cell)->JSMatrix0::~JSMatrix0();
    }

    void setPrivate(void* data);
    Matrix& getPrivate() const
    {
        return static_cast<Matrix&>(*m_privateData);
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
        auto* thisObject = jsCast<JSMatrix0*>(cell);
        ASSERT_GC_OBJECT_INHERITS(thisObject, info());
        Base::visitChildren(thisObject, visitor);
        thisObject->visitAdditionalChildren(visitor);
    }

    void init(ExecState*);
 
//    static JSMatrix0* asCallbackObject(JSValue);
//    static JSMatrix0* asCallbackObject(EncodedJSValue);
 
//    static EncodedJSValue JSC_HOST_CALL call(ExecState*);
//    static EncodedJSValue JSC_HOST_CALL construct(ExecState*);
   
    JSValue getStaticValue(ExecState*, PropertyName);
    static EncodedJSValue staticFunctionGetter(ExecState*, EncodedJSValue, PropertyName);
    static EncodedJSValue callbackGetter(ExecState*, EncodedJSValue, PropertyName);
    */

//    void* m_privateData;
    WTF::RefPtr<Matrix> m_privateData;
};
#endif /* JSMatrix0_h */
