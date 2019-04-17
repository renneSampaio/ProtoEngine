#ifndef __SHADER_HEADER__
#define __SHADER_HEADER__

#include <GL/glew.h>

#include <GL/gl.h>

namespace Proto {

class Shader {
  public:
    Shader(const char* vsPath, const char* fsPath);
    ~Shader();

    void Use();
    GLuint program();

  private:
    GLuint compileShader(const char* path, GLenum type);
    GLuint createProgram(GLuint vs, GLuint fs);
    bool checkCompilation(GLuint shader);

    GLuint _program;
};

} // namespace Proto

#endif
