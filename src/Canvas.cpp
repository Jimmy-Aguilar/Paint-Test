#include <Canvas.h>

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

void Canvas::tryToSelectShape(float x, float y) {
    if (selectedShape) {
        selectedShape->deselect();
        selectedShape = nullptr;
    }
    
    
    for (size_t i = 0; i < shapes.size(); i++) {
        if (shapes[i]->contains(x, y)) {
            selectedShape = shapes[i];
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

void Canvas::clear() {
    for (size_t i = 0; i < points.size(); i++) {
        delete points[i];
    }
    points.clear();
    
    for (size_t i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
}

void Canvas::render() {
    for (size_t i = 0; i < points.size(); i++) {
        points[i]->draw();
    }

    for (size_t i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}

Canvas::~Canvas() {
    clear();
}