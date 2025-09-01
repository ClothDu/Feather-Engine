#include <GLFW/glfw3.h>
#include <vector>
#include "Window.hpp"

int main() {
    Window window(600, 400, "window");

    while (!window.shouldClose()) {

        window.swapBuffers();
        window.pollEvents();
    }
    window.shouldClose();
    return 0;
}