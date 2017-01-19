#include "Rectangle.h"


int Rectangle::m_ref = 1;
Rectangle::Rectangle(float x, float y, float width, float height) {
    this->setTo(x, y, width, height);
}

Rectangle::~Rectangle()
{
    
}

void Rectangle::setTo(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

WTF::String Rectangle::toString() {
    return "(x=" + WTF::String::number(this->x) + ", y=" + WTF::String::number(this->y) +
           ", width=" + WTF::String::number(this->width) + ", height=" + WTF::String::number(this->height) + ")";
}
