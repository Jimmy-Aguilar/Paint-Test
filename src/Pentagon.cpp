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
    // Set the color for the pentagon
    glColor3f(color.r, color.g, color.b);
    
    // Draw the solid pentagon
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i) {
        // Calculate the vertices for a regular pentagon pointing upwards
        float angle = i * 2.0 * M_PI / 5.0 - M_PI / 2.0;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();

    // Draw a white outline if the shape is selected
    if (isSelected) {
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 5; ++i) {
            float angle = i * 2.0 * M_PI / 5.0 - M_PI / 2.0;
            glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
        }
        glEnd();
    }
}

bool Pentagon::contains(float _x, float _y) const {
    // Basic bounding box check using the radius
    return (_x >= x - radius && _x <= x + radius &&
            _y >= y - radius && _y <= y + radius);
}

Pentagon::~Pentagon() {
    //
}