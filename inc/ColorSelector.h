#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include <FL/Fl_Value_Slider.H> // Included native FLTK slider
#include <Enums.h>
#include <Color.h>

class ColorSelector : public bobcat::Group {
    Fl_Value_Slider* redSlider;
    Fl_Value_Slider* greenSlider;
    Fl_Value_Slider* blueSlider;
    bobcat::Button* previewBox;

    // FLTK requires a static callback function, so we will pass the class instance as 'data'
    static void onSliderChange(Fl_Widget* sender, void* data);
    
public:
    ColorSelector(int x, int y, int w, int h);

    Color getSelectedColor() const;

    ~ColorSelector();
};

#endif