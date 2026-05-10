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

    // FIX: Draw a white ring outline when selected to indicate selection.
    if (isSelected) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
            float inc2 = 2 * M_PI / 60;
            float innerR = radius * 0.75f;
            for (float theta = 0; theta <= 2 * M_PI; theta += inc2) {
                glVertex2f(x + innerR * cos(theta), y + innerR * sin(theta));
            }
        glEnd();
        glLineWidth(1.0f);
    }
}

// FIX: Properly implement point-in-circle test (was always returning false).
bool Circle::contains(float _x, float _y) const {
    float dx = _x - x;
    float dy = _y - y;
    return (dx * dx + dy * dy) <= (radius * radius);
}

float Circle::getRadius() const {
    return radius;
}
void Circle::setRadius(float _radius) {
    radius = _radius;
}

void Circle::resize(float factor) {
    radius *= factor;
}

Circle::~Circle() {
    
}