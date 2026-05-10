#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include <Enums.h>

class Toolbar : public bobcat::Group {
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* mouseButton;
    bobcat::Image* clearButton;
    bobcat::Image* undoButton;
    
    bobcat::Image* circleButton;
    bobcat::Image* triangleButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* pentagonButton;
    bobcat::Image* diamondButton;
    
    bobcat::Image* bringFrontButton;
    bobcat::Image* bringBackButton;
    
    bobcat::Image* plusButton;
    bobcat::Image* minusButton;
    
    TOOL selectedTool;
    ACTION action;
    
    void onClick(bobcat::Widget* sender);
    void visualizeSelectedTool() const;
    void deselectAllTools() const;

public:
    Toolbar(int x, int y, int w, int h);

    TOOL getSelectedTool() const;
    ACTION getAction() const;

    ~Toolbar();
};

#endif