#ifndef SHAPE_H
#define SHAPE_H

#include <Color.h>

class Shape {
protected:
    float x;
    float y;
    Color color;
    bool isSelected;

public:
    Shape();
    
    virtual void draw() const = 0;
    virtual bool contains(float _x, float _y) const = 0;
    virtual void resize(float factor) = 0; // New resizing method

    float getX() const;
    float getY() const;
    void setX(float _x);
    void setY(float _y);

    void select();
    void deselect();
    bool getIsSelected() const;

    void setColor(Color c);
    Color getColor() const;

    virtual ~Shape();
};

#endif