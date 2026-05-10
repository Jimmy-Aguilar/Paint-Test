#include <Toolbar.h>

using namespace bobcat;

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton    = new Image(x,      y,       50, 50, "./assets/pencil.png");
    eraserButton    = new Image(x + 50, y,       50, 50, "./assets/eraser.png");
    mouseButton     = new Image(x,      y + 50,  50, 50, "./assets/mouse.png");
    clearButton     = new Image(x + 50, y + 50,  50, 50, "./assets/clear.png");
    undoButton      = new Image(x,      y + 100, 50, 50, "./assets/undo.png");
    circleButton    = new Image(x + 50, y + 100, 50, 50, "./assets/circle.png");
    triangleButton  = new Image(x,      y + 150, 50, 50, "./assets/triangle.png");
    rectangleButton = new Image(x + 50, y + 150, 50, 50, "./assets/rectangle.png");
    pentagonButton  = new Image(x,      y + 200, 50, 50, "./assets/pentagon.png");
    diamondButton   = new Image(x + 50, y + 200, 50, 50, "./assets/diamond.png");
    plusButton      = new Image(x,      y + 250, 50, 50, "./assets/plus.png");
    minusButton     = new Image(x + 50, y + 250, 50, 50, "./assets/minus.png");
    bringFrontButton= new Image(x,      y + 300, 50, 50, "./assets/front.png");
    bringBackButton = new Image(x + 50, y + 300, 50, 50, "./assets/back.png");

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    mouseButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);
    undoButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    pentagonButton->box(FL_BORDER_BOX);
    diamondButton->box(FL_BORDER_BOX);
    plusButton->box(FL_BORDER_BOX);
    minusButton->box(FL_BORDER_BOX);
    bringFrontButton->box(FL_BORDER_BOX);
    bringBackButton->box(FL_BORDER_BOX);

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(mouseButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);
    ON_CLICK(undoButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(pentagonButton, Toolbar::onClick);
    ON_CLICK(diamondButton, Toolbar::onClick);
    ON_CLICK(plusButton, Toolbar::onClick);
    ON_CLICK(minusButton, Toolbar::onClick);
    ON_CLICK(bringFrontButton, Toolbar::onClick);
    ON_CLICK(bringBackButton, Toolbar::onClick);

    selectedTool = PENCIL;
    visualizeSelectedTool();
}

TOOL Toolbar::getSelectedTool() const { return selectedTool; }
ACTION Toolbar::getAction() const { return action; }

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();
    action = NONE;
    
    if (sender == pencilButton) { selectedTool = PENCIL; }
    else if (sender == eraserButton) { selectedTool = ERASER; }
    else if (sender == mouseButton) { selectedTool = MOUSE; }
    else if (sender == circleButton) { selectedTool = CIRCLE; }
    else if (sender == triangleButton) { selectedTool = TRIANGLE; }
    else if (sender == rectangleButton) { selectedTool = RECTANGLE; }
    else if (sender == pentagonButton) { selectedTool = PENTAGON; }
    else if (sender == diamondButton) { selectedTool = DIAMOND; }
    else if (sender == bringFrontButton) { selectedTool = BRING_FRONT; }
    else if (sender == bringBackButton) { selectedTool = BRING_BACK; }
    else if (sender == clearButton) { action = CLEAR; }
    else if (sender == undoButton) { action = UNDO; }
    else if (sender == plusButton) { action = ENLARGE; }
    else if (sender == minusButton) { action = MINIMIZE; }

    if (onChangeCb) { onChangeCb(this); }
    
    visualizeSelectedTool();
    redraw();
}

void Toolbar::visualizeSelectedTool() const {
    if (selectedTool == PENCIL) { pencilButton->color(FL_WHITE); }
    else if (selectedTool == ERASER) { eraserButton->color(FL_WHITE); }
    else if (selectedTool == MOUSE) { mouseButton->color(FL_WHITE); }
    else if (selectedTool == CIRCLE) { circleButton->color(FL_WHITE); }
    else if (selectedTool == TRIANGLE) { triangleButton->color(FL_WHITE); }
    else if (selectedTool == RECTANGLE) { rectangleButton->color(FL_WHITE); }
    else if (selectedTool == PENTAGON) { pentagonButton->color(FL_WHITE); }
    else if (selectedTool == DIAMOND) { diamondButton->color(FL_WHITE); }
    else if (selectedTool == BRING_FRONT) { bringFrontButton->color(FL_WHITE); }
    else if (selectedTool == BRING_BACK) { bringBackButton->color(FL_WHITE); }
}

void Toolbar::deselectAllTools() const {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    mouseButton->color(FL_BACKGROUND_COLOR);
    clearButton->color(FL_BACKGROUND_COLOR);
    undoButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    pentagonButton->color(FL_BACKGROUND_COLOR);
    diamondButton->color(FL_BACKGROUND_COLOR);
    plusButton->color(FL_BACKGROUND_COLOR);
    minusButton->color(FL_BACKGROUND_COLOR);
    bringFrontButton->color(FL_BACKGROUND_COLOR);
    bringBackButton->color(FL_BACKGROUND_COLOR);
}

Toolbar::~Toolbar() {
    delete pencilButton; delete eraserButton; delete mouseButton;
    delete clearButton; delete undoButton; delete circleButton;
    delete triangleButton; delete rectangleButton; delete pentagonButton;
    delete diamondButton; delete plusButton; delete minusButton;
    delete bringFrontButton; delete bringBackButton;
}