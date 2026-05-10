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
        glVertex2f(x,           y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();

    if (isSelected) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(2.0f);
        float s = 0.65f;
        glBegin(GL_LINE_LOOP);
            glVertex2f(x - (base * s)/2, y - (height * s)/2);
            glVertex2f(x,                 y + (height * s)/2);
            glVertex2f(x + (base * s)/2, y - (height * s)/2);
        glEnd();
        glLineWidth(1.0f);
    }
}


bool Triangle::contains(float _x, float _y) const {
    float x1 = x - base/2,  y1 = y - height/2;
    float x2 = x,            y2 = y + height/2;
    float x3 = x + base/2,  y3 = y - height/2;


    float d1 = (_x - x2) * (y1 - y2) - (x1 - x2) * (_y - y2);
    float d2 = (_x - x3) * (y2 - y3) - (x2 - x3) * (_y - y3);
    float d3 = (_x - x1) * (y3 - y1) - (x3 - x1) * (_y - y1);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
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

void Triangle::resize(float factor) {
    base   *= factor;
    height *= factor;
}

Triangle::~Triangle() {
    //
}