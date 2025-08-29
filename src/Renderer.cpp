#include "Renderer.hpp"
#include <glad/gl.h>

void Renderer::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const Mesh& mesh, const Shader& shader) {
    shader.use();
    mesh.draw();
}
