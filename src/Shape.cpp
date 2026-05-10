#include <Shape.h>

Shape::Shape() {
    x = 0.0;
    y = 0.0;
    color = {0, 0, 0};
    isSelected = false;
}

float Shape::getX() const { return x; }
float Shape::getY() const { return y; }
void Shape::setX(float _x) { x = _x; }
void Shape::setY(float _y) { y = _y; }

void Shape::select() { isSelected = true; }
void Shape::deselect() { isSelected = false; }
bool Shape::getIsSelected() const { return isSelected; }

void Shape::setColor(Color c) { color = c; }
Color Shape::getColor() const { return color; }

Shape::~Shape() {}