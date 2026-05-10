#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Shape.h>
#include <GL/freeglut.h>

class Triangle : public Shape {
    float base;
    float height;
    
public:
    Triangle();
    Triangle(float _x, float _y, float _base, float _height, Color _color);

    void draw() const;
    bool contains(float _x, float _y) const;

    float getBase() const;
    float getHeight() const;

    void setBase(float _base);
    void setHeight(float _height);
    
    void resize(float factor) override;

    ~Triangle();
};

#endif