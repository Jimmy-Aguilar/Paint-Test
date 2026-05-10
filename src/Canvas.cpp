#include <Canvas.h>
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : bobcat::Canvas_(x, y, w, h) {
    selectedShape = nullptr;
}

void Canvas::addPoint(float x, float y, Color color) {
    points.push_back(new Point(x, y, color));
}

void Canvas::addCircle(float x, float y, float radius, Color color) {
    shapes.push_back(new Circle(x, y, radius, color));
}

void Canvas::addTriangle(float x, float y, float base, float height, Color color) {
    shapes.push_back(new Triangle(x, y, base, height, color));
}

void Canvas::addRectangle(float x, float y, float width, float height, Color color) {
    shapes.push_back(new Rectangle(x, y, width, height, color));
}

void Canvas::addPentagon(float x, float y, float radius, Color color) {
    shapes.push_back(new Pentagon(x, y, radius, color));
}

void Canvas::addDiamond(float x, float y, float width, float height, Color color) {
    shapes.push_back(new Diamond(x, y, width, height, color));
}

void Canvas::tryToSelectShape(float x, float y) {
    if (selectedShape) {
        selectedShape->deselect();
        selectedShape = nullptr;
    }
    for (auto it = shapes.rbegin(); it != shapes.rend(); ++it) {
        if ((*it)->contains(x, y)) {
            selectedShape = *it;
            selectedShape->select();
            break; 
        }
    }
}

void Canvas::tryToMoveSelectedShape(float x, float y) {
    if (selectedShape) {
        selectedShape->setX(x);
        selectedShape->setY(y);
    }
}

void Canvas::enlargeSelectedShape() {
    if (selectedShape) {
        selectedShape->resize(1.1f); // Grow by 10%
    }
}

void Canvas::minimizeSelectedShape() {
    if (selectedShape) {
        selectedShape->resize(0.9f); // Shrink by 10%
    }
}

void Canvas::clear() {
    for (Point* p : points) { delete p; }
    points.clear();

    for (Shape* s : shapes) { delete s; }
    shapes.clear();
    
    selectedShape = nullptr;
}

void Canvas::render() {
    // FIX: Clears the background every frame to prevent trailing artifacts!
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (Point* p : points) {
        p->draw();
    }
    for (Shape* s : shapes) {
        s->draw();
    }
}

Canvas::~Canvas() {
    clear();
}