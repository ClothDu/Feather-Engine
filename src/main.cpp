#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Renderer.hpp"
#include <vector>

int main() {
    Window window(600, 400, "window");

    Shader shader("shaders/basic.vert", "shaders/basic.frag");

    std::vector<float> vertices = {
        // posições       // cores
        -0.5f, -0.5f, 0, 1, 0, 0,
         0.5f, -0.5f, 0, 0, 1, 0,
         0.0f,  0.5f, 0, 0, 0, 1
    };
    std::vector<unsigned int> indices = { 0, 1, 2 };

    Mesh mesh(vertices, indices);
    Renderer renderer;

    while (!window.shouldClose()) {
        renderer.clear(0.1f, 0.1f, 0.1f, 1.0f);

        renderer.draw(mesh, shader);

        window.swapBuffers();
        window.pollEvents();
    }
    window.shouldClose();
    return 0;
}