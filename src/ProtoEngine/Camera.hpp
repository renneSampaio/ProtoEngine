#ifndef CAMERA_HEADER_
#define CAMERA_HEADER_

#include <glm/gtc/matrix_transform.hpp>

#include "Component.hpp"

namespace Proto {

class Shader;

class Camera : public Component {
  public:
    Camera(float near, float far, float fovy);

    void setUniforms(Shader* shader);

    glm::mat4 getProjectionMatrix();
    glm::mat4 getViewMatrix();

    void update() override{};
    void render() override{};

    float getNear() const;
    void setNear(float near);

    float getFar() const;
    void setFar(float far);

    void setAspect(float aspect);

    float getFovy() const;
    void setFovy(float fovy);

  private:
    void calcProjection();
    void calcView();

    float _near;
    float _far;
    float _aspect;
    float _fovy;

    glm::mat4 _view;
    glm::mat4 _projection;
};

} // namespace Proto

#endif
