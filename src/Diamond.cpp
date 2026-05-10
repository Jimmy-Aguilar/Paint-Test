#include <Diamond.h>
#include <bobcat_ui/all.h>

Diamond::Diamond(float _x, float _y, float w, float h, Color c) {
    x = _x;
    y = _y;
    width = w;
    height = h;
    color = c;
    isSelected = false;
}

void Diamond::draw() const {
    glColor3f(color.r, color.g, color.b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x, y - height / 2);         
        glVertex2f(x + width / 2, y);      
        glVertex2f(x, y + height / 2);  
        glVertex2f(x - width / 2, y);     
    glEnd();

    if (isSelected) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y - height / 2);
            glVertex2f(x + width / 2, y);
            glVertex2f(x, y + height / 2);
            glVertex2f(x - width / 2, y);
        glEnd();
    }
}

void Diamond::resize(float factor) {
    width *= factor;
    height *= factor;
}

bool Diamond::contains(float _x, float _y) const {
    return (_x >= x - width/2 && _x <= x + width/2 &&
            _y >= y - height/2 && _y <= y + height/2);
}

Diamond::~Diamond() {
}