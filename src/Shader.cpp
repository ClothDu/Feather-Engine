#include <glad/gl.h>
#include "Shader.hpp"

GLuint Shader::compileShaders() {
    // Source code for vertex shader
    static const GLchar *vertex_shader_source[] = {
            "#version 450 core \n"
            " \n"
            "void main(void) \n"
            "{ \n"
            " gl_Position = vec4(0.0, 0.0, 0.5, 1.0); \n"
            "} \n"
        };
    // Source code for fragment shader
    static const GLchar *fragment_shader_source[] = {
            "#version 450 core \n"
            " \n"
            "out vec4 color; \n"
            " \n"
            "void main(void) \n"
            "{ \n"
            " color = vec4(0.0, 0.8, 1.0, 1.0); \n"
            "} \n"
        };
    // Create and compile vertex shader
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, vertex_shader_source, nullptr);
    glCompileShader(vertex_shader);
    // Create and compile fragment shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, fragment_shader_source, nullptr);
    glCompileShader(fragment_shader);
    // Create program, attach shaders to it, and link it
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    // Delete the shaders as the program has them now
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    return program;
}

void ShaderAply::startUp() {
    renderingProgram = compileShaders();
    glCreateVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);
}

void ShaderAply::shutDown() {
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteProgram(renderingProgram);
    glDeleteVertexArrays(1, &vertexArrayObject);
}