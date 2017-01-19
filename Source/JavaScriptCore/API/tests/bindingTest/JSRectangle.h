//
//  JSRectangle.h
//  JavaScriptCore
//
//  Created by liangshuochen on 14/01/2017.
//
//

#ifndef JSRectangle_h
#define JSRectangle_h

#include <stdio.h>
#include "Rectangle.h"

extern JSObjectRef JSRectangle_new(JSContextRef context, Rectangle* node);
extern JSClassRef JSRectangle_class(JSContextRef context);
extern void setRectangleIn(JSContextRef ctx, JSObjectRef parent, const char *name, JSClassRef jsClass);


#endif /* JSRectangle_h */
