//
//  JSMatrix.h
//  JavaScriptCore
//
//  Created by liangshuochen on 14/01/2017.
//
//

#ifndef JSMatrix_h
#define JSMatrix_h

#include "JSBase.h"
#include "Matrix.h"
#include <stddef.h>

extern JSObjectRef JSMatrix_new(JSContextRef context, Matrix* node);
extern JSClassRef JSMatrix_class(JSContextRef context);
extern void setMatrixIn(JSContextRef ctx, JSObjectRef parent, const char *name, JSClassRef jsClass);

#endif /* JSMatrix_h */
