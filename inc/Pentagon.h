#ifndef PENTAGON_H
#define PENTAGON_H

#include <Shape.h>

class Pentagon : public Shape {
    float radius;
public:
    Pentagon(float x, float y, float r, Color c);
    
    void draw() const override;
    bool contains(float _x, float _y) const override;

    void resize(float factor) override;

    // Added the destructor declaration here!
    ~Pentagon();
};

#endif