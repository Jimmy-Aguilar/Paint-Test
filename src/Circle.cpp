#include <Circle.h>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.2;
    color = {0, 0, 0};
}

Circle::Circle(float _x, float _y, float _radius, Color _color) {
    x = _x;
    y = _y;
    radius = _radius;
    color = _color;
}

void Circle::draw() const {
    glColor3f(color.r, color.g, color.b);

    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / 60;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
        }
    glEnd();
}

bool Circle::contains(float _x, float _y) const {
    return false;
}

float Circle::getRadius() const {
    return radius;
}
void Circle::setRadius(float _radius) {
    radius = _radius;
}

Circle::~Circle() {
    //
}