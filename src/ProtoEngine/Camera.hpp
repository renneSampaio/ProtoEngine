#ifndef CAMERA_HEADER_
#define CAMERA_HEADER_

#include <glm/gtc/matrix_transform.hpp>

#include "Component.hpp"

namespace ProtoEngine {

class Camera : public Component {
  public:
    float _near;
    float _far;
    float _aspect;
    float _fovy;

    Camera(float near, float far, float aspect, float fovy);

    glm::mat4 getProjection();
    glm::mat4 getView();

    void update() override{};
    void render() override{};
};

} // namespace ProtoEngine

#endif
