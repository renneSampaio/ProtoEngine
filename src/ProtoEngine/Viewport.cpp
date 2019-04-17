#include <GL/glew.h>

#include <GL/gl.h>

#include "Viewport.hpp"

namespace Proto {

Viewport::Viewport(int width, int height) : Viewport(0, 0, width, height){};
Viewport::Viewport(int x, int y, int width, int height)
    : _x(x), _y(y), _width(width), _height(height) {}

void Viewport::apply() {
    glViewport(this->_x, this->_y, this->_width, this->_height);
}

} // namespace Proto
