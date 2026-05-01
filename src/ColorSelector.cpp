#include <ColorSelector.h>

using namespace bobcat;

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    redButton = new Button(x, y, 50, 50, "");
    orangeButton = new Button(x + 50, y, 50, 50, "");
    yellowButton = new Button(x + 100, y, 50, 50, "");
    greenButton = new Button(x + 150, y, 50, 50, "");
    blueButton = new Button(x + 200, y, 50, 50, "");
    indigoButton = new Button(x + 250, y, 50, 50, "");
    violetButton = new Button(x + 300, y, 50, 50, "");

    redButton->color(fl_rgb_color(255, 0, 0));
    orangeButton->color(fl_rgb_color(255, 127, 0));
    yellowButton->color(fl_rgb_color(255, 255, 0));
    greenButton->color(fl_rgb_color(0, 255, 0));
    blueButton->color(fl_rgb_color(0, 0, 255));
    indigoButton->color(fl_rgb_color(75, 0, 130));
    violetButton->color(fl_rgb_color(148, 0, 211));

    redButton->labelcolor(FL_WHITE);
    orangeButton->labelcolor(FL_WHITE);
    yellowButton->labelcolor(FL_WHITE);
    greenButton->labelcolor(FL_WHITE);
    blueButton->labelcolor(FL_WHITE);
    indigoButton->labelcolor(FL_WHITE);
    violetButton->labelcolor(FL_WHITE);

    ON_CLICK(redButton, ColorSelector::onClick);
    ON_CLICK(orangeButton, ColorSelector::onClick);
    ON_CLICK(yellowButton, ColorSelector::onClick);
    ON_CLICK(greenButton, ColorSelector::onClick);
    ON_CLICK(blueButton, ColorSelector::onClick);
    ON_CLICK(indigoButton, ColorSelector::onClick);
    ON_CLICK(violetButton, ColorSelector::onClick);

    selectedColor = RED;
    visualizeSelectedColor();
}

Color ColorSelector::getSelectedColor() const {
    Color color = {0, 0, 0};

    if (selectedColor == RED) {
        color = {255/255.0, 0/255.0, 0/255.0};
    }
    else if (selectedColor == ORANGE) {
        color = {255/255.0, 127/255.0, 0/255.0};
    }
    else if (selectedColor == YELLOW) {
        color = {255/255.0, 255/255.0, 0/255.0};
    }
    else if (selectedColor == GREEN) {
        color = {0/255.0, 255/255.0, 0/255.0};
    }
    else if (selectedColor == BLUE) {
        color = {0/255.0, 0/255.0, 255/255.0};
    }
    else if (selectedColor == INDIGO) {
        color = {75/255.0, 0/255.0, 130/255.0};
    }
    else if (selectedColor == VIOLET) {
        color = {148/255.0, 0/255.0, 211/255.0};
    }

    return color;
}

void ColorSelector::onClick(Widget* sender) {
    deselectAllColors();
    
    if (sender == redButton) {
        selectedColor = RED;
    }
    else if (sender == orangeButton) {
        selectedColor = ORANGE;
    }
    else if (sender == yellowButton) {
        selectedColor = YELLOW;
    }
    else if (sender == greenButton) {
        selectedColor = GREEN;
    }
    else if (sender == blueButton) {
        selectedColor = BLUE;
    }
    else if (sender == indigoButton) {
        selectedColor = INDIGO;
    }
    else if (sender == violetButton) {
        selectedColor = VIOLET;
    }

    visualizeSelectedColor();
}

void ColorSelector::visualizeSelectedColor() const {
    if (selectedColor == RED) {
        redButton->label("@+5square");
    }
    else if (selectedColor == ORANGE) {
        orangeButton->label("@+5square");
    }
    else if (selectedColor == YELLOW) {
        yellowButton->label("@+5square");
    }
    else if (selectedColor == GREEN) {
        greenButton->label("@+5square");
    }
    else if (selectedColor == BLUE) {
        blueButton->label("@+5square");
    }
    else if (selectedColor == INDIGO) {
        indigoButton->label("@+5square");
    }
    else if (selectedColor == VIOLET) {
        violetButton->label("@+5square");
    }
}

void ColorSelector::deselectAllColors() const {
    redButton->label("");
    orangeButton->label("");
    yellowButton->label("");
    greenButton->label("");
    blueButton->label("");
    indigoButton->label("");
    violetButton->label("");
}

ColorSelector::~ColorSelector() {
    delete redButton;
    delete orangeButton;
    delete yellowButton;
    delete greenButton;
    delete blueButton;
    delete indigoButton;
    delete violetButton;
}