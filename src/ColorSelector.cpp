#include <ColorSelector.h>

using namespace bobcat;

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    redSlider = new Fl_Value_Slider(x + 20, y, 100, 20, "R");
    redSlider->type(FL_HOR_NICE_SLIDER);
    redSlider->bounds(0.0, 1.0);
    redSlider->step(0.01); // Added safeguard against division by 0
    redSlider->value(0.0);
    redSlider->align(FL_ALIGN_LEFT);
    
    greenSlider = new Fl_Value_Slider(x + 20, y + 25, 100, 20, "G");
    greenSlider->type(FL_HOR_NICE_SLIDER);
    greenSlider->bounds(0.0, 1.0);
    greenSlider->step(0.01); // Added safeguard against division by 0
    greenSlider->value(0.0);
    greenSlider->align(FL_ALIGN_LEFT);

    blueSlider = new Fl_Value_Slider(x + 20, y + 50, 100, 20, "B");
    blueSlider->type(FL_HOR_NICE_SLIDER);
    blueSlider->bounds(0.0, 1.0);
    blueSlider->step(0.01); // Added safeguard against division by 0
    blueSlider->value(0.0);
    blueSlider->align(FL_ALIGN_LEFT);

    previewBox = new Button(x + 140, y + 10, 50, 50, "");
    previewBox->box(FL_FLAT_BOX);

    redSlider->callback(ColorSelector::onSliderChange, this);
    greenSlider->callback(ColorSelector::onSliderChange, this);
    blueSlider->callback(ColorSelector::onSliderChange, this);

    ColorSelector::onSliderChange(redSlider, this);
}

Color ColorSelector::getSelectedColor() const {
    return { 
        (float)redSlider->value(), 
        (float)greenSlider->value(), 
        (float)blueSlider->value() 
    };
}

void ColorSelector::onSliderChange(Fl_Widget* sender, void* data) {
    ColorSelector* selector = (ColorSelector*)data;
    Color c = selector->getSelectedColor();
    
    selector->previewBox->color(fl_rgb_color(c.r * 255, c.g * 255, c.b * 255));
    selector->redraw();
}

ColorSelector::~ColorSelector() {
    delete redSlider;
    delete greenSlider;
    delete blueSlider;
    delete previewBox;
}