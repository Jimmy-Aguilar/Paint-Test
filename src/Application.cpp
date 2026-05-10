#include <Application.h>

using namespace bobcat;

Application::Application() {
    window        = new Window(25, 75, 450, 450, "Paint Application");
    canvas        = new Canvas(100, 0, 350, 350);
    toolbar       = new Toolbar(0, 0, 100, 450);
    colorSelector = new ColorSelector(100, 350, 350, 100);

    window->add(canvas);
    window->add(toolbar);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG      (canvas, Application::onCanvasMouseDrag);
    ON_MOUSE_UP  (canvas, Application::onCanvasMouseUp);   
    
    ON_CHANGE    (toolbar,       Application::onToolbarChange);
    ON_CHANGE    (colorSelector, Application::onColorChange); 
    window->show();
}


void Application::onCanvasMouseDown(bobcat::Widget* sender, float x, float y) {
    Color color = colorSelector->getSelectedColor();
    TOOL  tool  = toolbar->getSelectedTool();

    if      (tool == PENCIL)    { canvas->beginScribble(x, y, color); }
    else if (tool == ERASER)    { canvas->beginScribble(x, y, {1.0f, 1.0f, 1.0f}); }
    else if (tool == CIRCLE)    { canvas->addCircle(x, y, 0.1f, color); }
    else if (tool == TRIANGLE)  { canvas->addTriangle(x, y, 0.2f, 0.2f, color); }
    else if (tool == RECTANGLE) { canvas->addRectangle(x, y, 0.2f, 0.2f, color); }
    else if (tool == DIAMOND)   { canvas->addDiamond(x, y, 0.2f, 0.2f, color); }
    else if (tool == PENTAGON)  { canvas->addPentagon(x, y, 0.15f, color); }
    else if (tool == MOUSE)     { canvas->tryToSelectShape(x, y); }

    canvas->redraw();
}


void Application::onCanvasMouseDrag(bobcat::Widget* sender, float x, float y) {
    TOOL tool = toolbar->getSelectedTool();

    if      (tool == PENCIL) { canvas->continueScribble(x, y); }
    else if (tool == ERASER) { canvas->continueScribble(x, y); }
    else if (tool == MOUSE)  { canvas->tryToMoveSelectedShape(x, y); }

    canvas->redraw();
}


void Application::onCanvasMouseUp(bobcat::Widget* sender, float x, float y) {
    if (toolbar->getSelectedTool() == PENCIL || toolbar->getSelectedTool() == ERASER) {
        canvas->endScribble();
        canvas->redraw();
    }
}


void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();
    TOOL   tool   = toolbar->getSelectedTool();

    if      (action == CLEAR)    { canvas->clear(); }
    else if (action == ENLARGE)  { canvas->enlargeSelectedShape(); }
    else if (action == MINIMIZE) { canvas->minimizeSelectedShape(); }
    else if (action == UNDO)     { canvas->undo(); }
    else if (tool   == BRING_FRONT) { canvas->bringSelectedToFront(); }
    else if (tool   == BRING_BACK)  { canvas->sendSelectedToBack(); }

    canvas->redraw();
}


void Application::onColorChange(bobcat::Widget* sender) {
    canvas->changeSelectedColor(colorSelector->getSelectedColor());
    canvas->redraw();
}

Application::~Application() {
    delete canvas;
    delete toolbar;
    delete colorSelector;
    delete window;
}