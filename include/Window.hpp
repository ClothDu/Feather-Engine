#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <GLFW/glfw3.h>
#include <string>

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