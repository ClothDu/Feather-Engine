#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

class Window {
    private:
        GLFWwindow *window;
        int width, heigth;
        std::string name;
    public:
        Window(int w, int h, const std::string &n);
        ~Window();

        void pollEvents();
        void swapBuffers();
        bool shouldClose() const;
};

#endif