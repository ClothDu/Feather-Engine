#include <iostream>
#include "Window.hpp"

int main() {
    Window window(600, 400, "window");
    while (!window.shouldClose()) {
        window.pollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.swapBuffers();
    }
    return 0;
}