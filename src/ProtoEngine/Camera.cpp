#include "Camera.hpp"
#include "Node.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace ProtoEngine {

Camera::Camera(float near, float far, float aspect, float fovy)
    : near(near), far(far), aspect(aspect), fovy(fovy) {}

glm::mat4 Camera::get_projection() {
    return glm::perspective(glm::radians(fovy), aspect, near, far);
}

glm::mat4 Camera::get_view() {
    return glm::translate(glm::mat4(1.0f), (node->position) * -1.0f);
}

} // namespace ProtoEngine
