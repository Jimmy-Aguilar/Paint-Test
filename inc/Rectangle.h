#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Shape.h>
#include <GL/freeglut.h>

class Rectangle : public Shape {
    float width;
    float height;
    
public:
    Rectangle();
    Rectangle(float _x, float _y, float _width, float _height, Color _color);

    void draw() const;
    bool contains(float _x, float _y) const;

    float getWidth() const;
    float getHeight() const;

    void setWidth(float _width);
    void setHeight(float _height);

    ~Rectangle();
};

#endif