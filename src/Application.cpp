#include <Application.h>
using namespace bobcat;

Application::Application() {
    window = new Window(25, 75, 400, 400, "GUI App");

    window->show();
}