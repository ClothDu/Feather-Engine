#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <glad/gl.h>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    void setUniformMat4(const std::string &name, const float* value) const;
    void setUniformVec3(const std::string &name, float x, float y, float z) const;

private:
    std::string loadFile(const char* path);
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif