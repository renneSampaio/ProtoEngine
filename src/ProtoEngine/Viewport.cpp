#include <GL/glew.h>

#include <GL/gl.h>

#include "Viewport.hpp"

namespace Proto {

Viewport::Viewport(int width, int height) : Viewport(0, 0, width, height){};
Viewport::Viewport(int x, int y, int width, int height)
    : _x(x), _y(y), _width(width), _height(height) {
    updateAspectRatio();
}

void Viewport::setup() {
    glViewport(this->_x, this->_y, this->_width, this->_height);
    glScissor(this->_x, this->_y, this->_width, this->_height);
}

void Viewport::applyBackground() {
    glClearColor(_clearColor.r, _clearColor.g, _clearColor.b, _clearColor.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Viewport::setClearColor(float r, float g, float b, float a) {
    _clearColor.r = r;
    _clearColor.g = g;
    _clearColor.b = b;
    _clearColor.a = a;
}

void Viewport::setScene(Scene* scene) { _scene = scene; }

Scene* Viewport::getScene() { return _scene; }

void Viewport::setCamera(Camera* camera) { _camera = camera; }

Camera* Viewport::getCamera() { return _camera; }

} // namespace Proto
