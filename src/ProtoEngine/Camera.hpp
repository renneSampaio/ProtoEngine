#ifndef CAMERA_HEADER_
#define CAMERA_HEADER_

#include <glm/gtc/matrix_transform.hpp>

#include "Component.hpp"

namespace ProtoEngine {

class Camera : public Component {
  public:
    float near;
    float far;
    float aspect;
    float fovy;

    Camera(float near, float far, float aspect, float fovy);

    glm::mat4 get_projection();
    glm::mat4 get_view();

    void update() override{};
    void render() override{};
};

} // namespace ProtoEngine

#endif
