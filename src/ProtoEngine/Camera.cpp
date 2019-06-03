#include "Camera.hpp"
#include "Node.hpp"
#include "Shader.hpp"

#include <glm/gtc/type_ptr.hpp>

namespace Proto {

Camera::Camera(float near, float far, float fovy)
    : _near(near), _far(far), _fovy(fovy) {}

void Camera::setUniforms(Shader* shader) {

    calcProjection();
    calcView();

    GLuint viewLoc = glGetUniformLocation(shader->program(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(_view));

    GLuint projectionLoc =
        glGetUniformLocation(shader->program(), "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(_projection));
}

Mat4& Camera::getProjectionMatrix() {
    calcProjection();
    return _projection;
}

Mat4& Camera::getViewMatrix() {
    calcView();
    return _view;
}

float Camera::getNear() const { return _near; }

void Camera::setNear(float near) { _near = near; }

float Camera::getFar() const { return _far; }

void Camera::setFar(float far) { _far = far; }

float Camera::getFovy() const { return _fovy; }

void Camera::setFovy(float fovy) { _fovy = fovy; }

void Camera::setAspect(float aspect) { _aspect = aspect; }

void Camera::calcProjection() {
    _projection = glm::perspective(glm::radians(_fovy), _aspect, _near, _far);
}

void Camera::calcView() {
    _view = glm::translate(glm::mat4(1.0f), (getNode()->getPosition()) * -1.0f);
}

} // namespace Proto
