#include "Camera.hpp"
#include "Node.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace ProtoEngine {

Camera::Camera(float near, float far, float aspect, float fovy)
    : _near(near), _far(far), _aspect(aspect), _fovy(fovy) {}

glm::mat4 Camera::getProjection() {
    return glm::perspective(glm::radians(_fovy), _aspect, _near, _far);
}

glm::mat4 Camera::getView() {
    return glm::translate(glm::mat4(1.0f), (getNode()->getPosition()) * -1.0f);
}

float Camera::getNear() const { return _near; }

void Camera::setNear(float near) { _near = near; }

float Camera::getFar() const { return _far; }

void Camera::setFar(float far) { _far = far; }

float Camera::getAspect() const { return _aspect; }

void Camera::setAspect(float aspect) { _aspect = aspect; }

float Camera::getFovy() const { return _fovy; }

void Camera::setFovy(float fovy) { _fovy = fovy; }

} // namespace ProtoEngine
