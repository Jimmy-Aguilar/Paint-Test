#include <ColorSelector.h>

using namespace bobcat;

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    // FIX: Changed bounds from (0.0, 1.0) to (0.0, 255.0) so the display shows
    //      standard 0-255 RGB values instead of a tiny 0.0-1.0 decimal fraction.
    redSlider = new Fl_Value_Slider(x + 20, y, 100, 20, "R");
    redSlider->type(FL_HOR_NICE_SLIDER);
    redSlider->bounds(0.0, 255.0);
    redSlider->step(1.0);
    redSlider->value(0.0);
    redSlider->align(FL_ALIGN_LEFT);
    
    greenSlider = new Fl_Value_Slider(x + 20, y + 25, 100, 20, "G");
    greenSlider->type(FL_HOR_NICE_SLIDER);
    greenSlider->bounds(0.0, 255.0);
    greenSlider->step(1.0);
    greenSlider->value(0.0);
    greenSlider->align(FL_ALIGN_LEFT);

    blueSlider = new Fl_Value_Slider(x + 20, y + 50, 100, 20, "B");
    blueSlider->type(FL_HOR_NICE_SLIDER);
    blueSlider->bounds(0.0, 255.0);
    blueSlider->step(1.0);
    blueSlider->value(0.0);
    blueSlider->align(FL_ALIGN_LEFT);

    previewBox = new Button(x + 140, y + 10, 50, 50, "");
    previewBox->box(FL_FLAT_BOX);

    redSlider->callback(ColorSelector::onSliderChange, this);
    greenSlider->callback(ColorSelector::onSliderChange, this);
    blueSlider->callback(ColorSelector::onSliderChange, this);

    ColorSelector::onSliderChange(redSlider, this);
}

// FIX: Divide each slider value (0-255) by 255 to produce the 0.0-1.0 Color
//      components expected by glColor3f and the rest of the drawing code.
Color ColorSelector::getSelectedColor() const {
    return { 
        (float)redSlider->value()   / 255.0f, 
        (float)greenSlider->value() / 255.0f, 
        (float)blueSlider->value()  / 255.0f
    };
}

void ColorSelector::onSliderChange(Fl_Widget* sender, void* data) {
    ColorSelector* selector = (ColorSelector*)data;
    Color c = selector->getSelectedColor(); // already 0.0-1.0
    
    // fl_rgb_color expects 0-255 integers, so multiply the 0-1 floats back up.
    selector->previewBox->color(fl_rgb_color(
        (unsigned char)(c.r * 255),
        (unsigned char)(c.g * 255),
        (unsigned char)(c.b * 255)
    ));
    selector->redraw();
}

ColorSelector::~ColorSelector() {
    delete redSlider;
    delete greenSlider;
    delete blueSlider;
    delete previewBox;
}