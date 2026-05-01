#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include <Enums.h>
#include <Color.h>

class ColorSelector : public bobcat::Group {
    bobcat::Button* redButton;
    bobcat::Button* orangeButton;
    bobcat::Button* yellowButton;
    bobcat::Button* greenButton;
    bobcat::Button* blueButton;
    bobcat::Button* indigoButton;
    bobcat::Button* violetButton;

    COLOR selectedColor;
    void onClick(bobcat::Widget* sender);
    void visualizeSelectedColor() const;
    void deselectAllColors() const;
    
public:
    ColorSelector(int x, int y, int w, int h);

    Color getSelectedColor() const;

    ~ColorSelector();
};

#endif