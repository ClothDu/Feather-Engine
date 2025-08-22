#include <iostream>
#include <math.h>
#include "Window.hpp"

int main() {
    Window window(600, 400, "window");
    while (!window.shouldClose()) {
        window.pollEvents();

        const GLfloat color[] = {(float)sin(glfwGetTime()) * 0.5f + 0.5f, (float)cos(glfwGetTime()) * 0.5f + 0.5f, 0, 1};

        glClearBufferfv(GL_COLOR, 0, color);

        window.swapBuffers();
    }
    return 0;
}