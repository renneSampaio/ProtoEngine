#include <GL/glew.h>

#include <GL/gl.h>

#include "Viewport.hpp"

namespace ProtoEngine {

Viewport::Viewport(int width, int height) : Viewport(0, 0, width, height){};
Viewport::Viewport(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}

void Viewport::apply() {
    glViewport(this->x, this->y, this->width, this->height);
}

} // namespace ProtoEngine
