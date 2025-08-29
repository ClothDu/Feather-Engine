#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <glad/gl.h>

class Mesh {
public:
    Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();
    void draw() const;

private:
    unsigned int VAO, VBO, EBO;
    unsigned int indexCount;
};

#endif
