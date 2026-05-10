#ifndef DIAMOND_H
#define DIAMOND_H

#include <Shape.h>

class Diamond : public Shape {
    float width;
    float height;
public:
    Diamond(float x, float y, float w, float h, Color c);
    
    void draw() const override;
    bool contains(float _x, float _y) const override;

    void resize(float factor) override;

    ~Diamond(); 
};

#endif