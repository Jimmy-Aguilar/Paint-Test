#include <Pentagon.h>
#include <bobcat_ui/all.h>
#include <cmath>

Pentagon::Pentagon(float _x, float _y, float r, Color c) {
    x = _x;
    y = _y;
    radius = r;
    color = c;
    isSelected = false;
}

void Pentagon::draw() const {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i) {
        float angle = i * 2.0 * M_PI / 5.0 + M_PI / 2.0;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();

    if (isSelected) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 5; ++i) {
            float angle = i * 2.0 * M_PI / 5.0 + M_PI / 2.0;
            glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
        }
        glEnd();
    }
}

void Pentagon::resize(float factor) {
    radius *= factor;
}

bool Pentagon::contains(float _x, float _y) const {
    return (_x >= x - radius && _x <= x + radius &&
            _y >= y - radius && _y <= y + radius);
}

Pentagon::~Pentagon() {
    //
}