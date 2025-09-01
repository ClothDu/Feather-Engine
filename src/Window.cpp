#include "Window.hpp"
#include <stdexcept>
#include <iostream>

static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

Window::Window(int w, int h, const std::string &n) : window(nullptr), width(w), heigth(h), name(n) {
    if (!glfwInit()) {
        glfwTerminate();
        throw std::runtime_error("error to init GLFW");
    }

    window = glfwCreateWindow(width, heigth, name.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("error to init Window contex");
    }
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetKeyCallback(window, key_callback);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::pollEvents() {
    glfwPollEvents();
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}