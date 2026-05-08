#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include <Enums.h>

class Toolbar : public bobcat::Group {
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* mouseButton;
    bobcat::Image* circleButton;
    bobcat::Image* triangleButton;
    bobcat::Image* pentagonButton;
    
    bobcat::Image* paintbrushButton;
    bobcat::Image* clearButton;
    bobcat::Image* bringFrontButton;
    bobcat::Image* bringBackButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* diamondButton;
    
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