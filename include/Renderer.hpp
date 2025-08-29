#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Shader.hpp"
#include "Mesh.hpp"

class Renderer {
public:
    void clear(float r, float g, float b, float a);
    void draw(const Mesh& mesh, const Shader& shader);
};

#endif
