#include <Application.h>

using namespace bobcat;

Application::Application() {
    window = new Window(25, 75, 450, 450, "Bobcat UI - Paint Application");

    // Shift canvas x to 100 because the toolbar is now 2 columns (100px) wide
    canvas = new Canvas(100, 0, 350, 350);
    toolbar = new Toolbar(0, 0, 100, 450);
    colorSelector = new ColorSelector(100, 350, 350, 100);

    window->add(canvas);
    window->add(toolbar);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasMouseDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}

void Application::onCanvasMouseDown(bobcat::Widget* sender, float x, float y) {
    Color color = colorSelector->getSelectedColor();
    TOOL tool = toolbar->getSelectedTool();
    
    if (tool == PENCIL) {
        canvas->addPoint(x, y, color); 
    }
    else if (tool == ERASER) {
        canvas->addPoint(x, y, {1.0, 1.0, 1.0}); // Assuming background is white
    }
    else if (tool == CIRCLE) {
        canvas->addCircle(x, y, 0.1, color);
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(x, y, 0.2, 0.2, color);
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(x, y, 0.2, 0.2, color);
    }
    else if (tool == DIAMOND) {
        canvas->addDiamond(x, y, 0.2, 0.2, color);
    }
    else if (tool == PENTAGON) {
        canvas->addPentagon(x, y, 0.15, color);
    }
    else if (tool == MOUSE) {
        canvas->tryToSelectShape(x, y);
    }
    
    canvas->redraw();
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
}

void Application::onCanvasMouseDrag(bobcat::Widget* sender, float x, float y) {
    Color color = colorSelector->getSelectedColor();
    TOOL tool = toolbar->getSelectedTool();
    
    if (tool == PENCIL || tool == PAINTBRUSH) {
        canvas->addPoint(x, y, color); 
    }
    else if (tool == ERASER) {
        canvas->addPoint(x, y, {1.0, 1.0, 1.0}); 
    }
    else if (tool == MOUSE) {
        canvas->tryToMoveSelectedShape(x, y);
    }
    
    canvas->redraw();
}

Application::~Application() {
    delete canvas;
    delete toolbar;
    delete colorSelector;
    delete window;
}