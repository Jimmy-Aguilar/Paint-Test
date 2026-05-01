#ifndef CIRCLE_H
#define CIRCLE_H

#include <Shape.h>
#include <GL/freeglut.h>
#include <cmath>

class Circle : public Shape {
    float radius;
    
public:
    Circle();
    Circle(float _x, float _y, float _radius, Color _color);

    void draw() const;
    bool contains(float _x, float _y) const;

    float getRadius() const;
    void setRadius(float _radius);

    ~Circle();
};

#endif