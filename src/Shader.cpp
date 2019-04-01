#include "Shader.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Shader::Shader(const char *vsPath, const char *fsPath) {
    GLuint vs = compileShader(vsPath, GL_VERTEX_SHADER);
    GLuint fs = compileShader(fsPath, GL_FRAGMENT_SHADER);

    GLuint program = createProgram(vs, fs);
    this->_program = program;
}

Shader::~Shader() { glDeleteProgram(_program); }

GLuint Shader::compileShader(const char *path, GLenum type) {
    std::ifstream file;
    file.open(path, std::ios::in);

    if (!file.is_open()) {
        std::cout << path << ": File not found\n";
    }

    file.seekg(0, file.end);
    GLint size = file.tellg();
    file.seekg(0, file.beg);

    char *source = new char[size];
    file.read(source, size);
    file.close();

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, (const GLchar **)&source, &size);
    glCompileShader(shader);

    checkCompilation(shader);

    delete[] source;

    return shader;
}

GLuint Shader::createProgram(GLuint vs, GLuint fs) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    return program;
}

bool Shader::checkCompilation(GLuint shader) {
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    if (status != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(shader, 512, nullptr, buffer);
        if (status == GL_FALSE)
            std::cout << buffer << std::endl;

        return false;
    }

    return true;
}

void Shader::Use() { glUseProgram(_program); }

GLuint Shader::program() { return this->_program; }
