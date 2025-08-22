#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/gl.h>

class Shader {
    private:
        GLuint vertex_shader;
        GLuint fragment_shader;
        GLuint program;
    
    public:
        GLuint compileShaders();
};

class ShaderAply : public Shader {
    private:
        GLuint renderingProgram;
        GLuint vertexArrayObject;

    public:
        void startUp();
        void shutDown();
};

#endif