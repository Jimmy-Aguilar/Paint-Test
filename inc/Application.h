#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include <Canvas.h>
#include <ColorSelector.h>
#include <Toolbar.h>
#include <Color.h>

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    Canvas* canvas;
    Toolbar* toolbar;
    ColorSelector* colorSelector;

    void onCanvasMouseDown(bobcat::Widget* sender, float x, float y);
    void onCanvasMouseDrag(bobcat::Widget* sender, float x, float y);
    void onToolbarChange(bobcat::Widget* sender);

public:
    Application();

    ~Application();
};

#endif

