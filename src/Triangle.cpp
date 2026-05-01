#include <Triangle.h>

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    base = 0.2;
    height = 0.2;
    color = {0, 0, 0};
}

Triangle::Triangle(float _x, float _y, float _base, float _height, Color _color) {
    x = _x;
    y = _y;
    base = _base;
    height = _height;
    color = _color;
}

void Triangle::draw() const {
    glColor3f(color.r, color.g, color.b);

    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();
}

bool Triangle::contains(float _x, float _y) const {
    return false;
}

float Triangle::getBase() const {
    return base;
}
float Triangle::getHeight() const {
    return height;
}
void Triangle::setBase(float _base) {
    base = _base;
}
void Triangle::setHeight(float _height) {
    height = _height;
}

Triangle::~Triangle() {
    //
}