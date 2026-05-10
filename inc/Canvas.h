#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/canvas.h>
#include <Scribble.h>
#include <Circle.h>
#include <Triangle.h>
#include <Rectangle.h>
#include <Pentagon.h>
#include <Diamond.h>
#include <Shape.h>
#include <vector>
#include <algorithm>

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;

    Shape*    selectedShape;
    Scribble* currentScribble;

    std::vector<Shape*> undoStack;

public:
    Canvas(int x, int y, int w, int h);

    void beginScribble(float x, float y, Color color);
    void continueScribble(float x, float y);
    void endScribble();

    void addCircle(float x, float y, float radius, Color color);
    void addTriangle(float x, float y, float base, float height, Color color);
    void addRectangle(float x, float y, float width, float height, Color color);
    void addPentagon(float x, float y, float radius, Color color);
    void addDiamond(float x, float y, float width, float height, Color color);

    void tryToSelectShape(float x, float y);
    void tryToMoveSelectedShape(float x, float y);

    void enlargeSelectedShape();
    void minimizeSelectedShape();
    void bringSelectedToFront();
    void sendSelectedToBack();

    void eraseAtPosition(float x, float y);

    void changeSelectedColor(Color c);

    void undo();
    void clear();
    void render();

    ~Canvas();
};

#endif