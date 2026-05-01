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

    float getX() const;
    float getY() const;
    Color getColor() const;
    bool getIsSelected() const;

    virtual void draw() const = 0;
    virtual bool contains(float _x, float _y) const = 0;

    void setX(float _x);
    void setY(float _y);
    void setColor(Color _color);
    void select();
    void deselect();

    virtual ~Shape();
};

#endif