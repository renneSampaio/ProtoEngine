#ifndef CAMERA_HEADER_
#define CAMERA_HEADER_

#include <glm/gtc/matrix_transform.hpp>

#include "ProtoTypes.hpp"

namespace Proto {

class Camera : public Component {
  public:
    Camera(Float near, Float far, Float fovy);

    void setUniforms(Shader* shader);

    Mat4& getProjectionMatrix();
    Mat4& getViewMatrix();

    void update() override{};
    void render() override{};

    Float getNear() const;
    void setNear(float near);

    Float getFar() const;
    void setFar(float far);

    void setAspect(float aspect);

    Float getFovy() const;
    void setFovy(float fovy);

  private:
    void calcProjection();
    void calcView();

    Float _near;
    Float _far;
    Float _aspect;
    Float _fovy;

    Mat4 _view;
    Mat4 _projection;
};

} // namespace Proto

#endif
