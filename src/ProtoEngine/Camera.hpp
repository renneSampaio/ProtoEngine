#ifndef CAMERA_HEADER_
#define CAMERA_HEADER_

#include <glm/gtc/matrix_transform.hpp>

#include "Component.hpp"

namespace ProtoEngine {

class Camera : public Component {
  public:
    Camera(float near, float far, float aspect, float fovy);

    glm::mat4 getProjection();
    glm::mat4 getView();

    void update() override{};
    void render() override{};

    float getNear() const;
    void setNear(float near);

    float getFar() const;
    void setFar(float far);

    float getAspect() const;
    void setAspect(float aspect);

    float getFovy() const;
    void setFovy(float fovy);

  private:
    float _near;
    float _far;
    float _aspect;
    float _fovy;
};

} // namespace ProtoEngine

#endif
