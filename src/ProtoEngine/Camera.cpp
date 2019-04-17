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
    return glm::translate(glm::mat4(1.0f), (_node->_position) * -1.0f);
}

} // namespace ProtoEngine
