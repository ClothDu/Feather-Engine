#include "Window.hpp"
#include <stdexcept>
#include <iostream>

Window::Window(int w, int h, const std::string &n) : window(nullptr), width(w), heigth(h), name(n) {
    if (!glfwInit()) {
        throw std::runtime_error("error to init GLFW");
        glfwTerminate();
    }

    window = glfwCreateWindow(width, heigth, name.c_str(), nullptr, nullptr);
    if (!window) {
        throw std::runtime_error("error to init Window contex");
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(window);
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        throw std::runtime_error("error to intialize openGL context");
    } else {
        std::cout << "sucefully load openGL " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;
    }
    glViewport(0, 0, width, heigth);
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

static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}