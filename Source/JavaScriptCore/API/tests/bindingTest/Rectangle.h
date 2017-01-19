#ifndef V8PERFORMANCE_RECTANGLE_H
#define V8PERFORMANCE_RECTANGLE_H

#include <wtf/text/WTFString.h>

class Rectangle : public RefCounted<Rectangle>
{
public:
    ~Rectangle();
    void ref() { m_ref++; }
    void deref() { m_ref--; }

    Rectangle(float x = 0, float y = 0, float width = 0, float height = 0);

    void setTo(float x, float y, float width, float height);

    WTF::String toString();

    float x, y, width, height;
    
private:
    static int m_ref;
};


#endif //V8PERFORMANCE_RECTANGLE_H
