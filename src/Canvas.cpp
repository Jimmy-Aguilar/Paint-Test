#include <Canvas.h>
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : bobcat::Canvas_(x, y, w, h) {
    selectedShape   = nullptr;
    currentScribble = nullptr;
}


void Canvas::beginScribble(float x, float y, Color color) {
    if (currentScribble) { endScribble(); }
    currentScribble = new Scribble(color);
    currentScribble->addPoint(x, y);
}

void Canvas::continueScribble(float x, float y) {
    if (currentScribble) { currentScribble->addPoint(x, y); }
}

void Canvas::endScribble() {
    if (!currentScribble) return;
    if (!currentScribble->empty()) {
        shapes.push_back(currentScribble);
        undoStack.clear();
    } else {
        delete currentScribble;
    }
    currentScribble = nullptr;
}


void Canvas::addCircle(float x, float y, float radius, Color color) {
    shapes.push_back(new Circle(x, y, radius, color));
    undoStack.clear();
}

void Canvas::addTriangle(float x, float y, float base, float height, Color color) {
    shapes.push_back(new Triangle(x, y, base, height, color));
    undoStack.clear();
}

void Canvas::addRectangle(float x, float y, float width, float height, Color color) {
    shapes.push_back(new Rectangle(x, y, width, height, color));
    undoStack.clear();
}

void Canvas::addPentagon(float x, float y, float radius, Color color) {
    shapes.push_back(new Pentagon(x, y, radius, color));
    undoStack.clear();
}

void Canvas::addDiamond(float x, float y, float width, float height, Color color) {
    shapes.push_back(new Diamond(x, y, width, height, color));
    undoStack.clear();
}


void Canvas::tryToSelectShape(float x, float y) {
    if (selectedShape) { selectedShape->deselect(); selectedShape = nullptr; }
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


void Canvas::enlargeSelectedShape()  { if (selectedShape) selectedShape->resize(1.1f); }
void Canvas::minimizeSelectedShape() { if (selectedShape) selectedShape->resize(0.9f); }

void Canvas::bringSelectedToFront() {
    if (!selectedShape) return;
    auto it = std::find(shapes.begin(), shapes.end(), selectedShape);
    if (it != shapes.end()) { shapes.erase(it); shapes.push_back(selectedShape); }
}

void Canvas::sendSelectedToBack() {
    if (!selectedShape) return;
    auto it = std::find(shapes.begin(), shapes.end(), selectedShape);
    if (it != shapes.end()) { shapes.erase(it); shapes.insert(shapes.begin(), selectedShape); }
}



void Canvas::eraseAtPosition(float x, float y) {
    for (auto it = shapes.rbegin(); it != shapes.rend(); ++it) {
        if ((*it)->contains(x, y)) {
            if (*it == selectedShape) { selectedShape = nullptr; }
            delete *it;
            shapes.erase((it + 1).base());
            return; 
        }
    }
}



void Canvas::changeSelectedColor(Color c) {
    if (selectedShape) { selectedShape->setColor(c); }
}


void Canvas::undo() {
    if (shapes.empty()) return;
    Shape* last = shapes.back();
    if (last == selectedShape) { last->deselect(); selectedShape = nullptr; }
    undoStack.push_back(last);
    shapes.pop_back();
}


void Canvas::clear() {
    if (currentScribble) { delete currentScribble; currentScribble = nullptr; }
    for (Shape* s : shapes)   { delete s; } shapes.clear();
    for (Shape* s : undoStack) { delete s; } undoStack.clear();
    selectedShape = nullptr;
}

void Canvas::render() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (Shape* s : shapes) { s->draw(); }

    if (currentScribble) { currentScribble->draw(); }

    glFlush();
}

Canvas::~Canvas() { clear(); }