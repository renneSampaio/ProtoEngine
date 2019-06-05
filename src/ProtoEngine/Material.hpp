#ifndef MATERIAL_HEADER_
#define MATERIAL_HEADER_

#include "ProtoTypes.hpp"

namespace Proto {

class Material {
  public:
    Material(Shader* shader);
    virtual ~Material();

    void setProperty(String name, Float& value);
    void setProperty(String name, Vec3& value);
    void setProperty(String name, Vec4& value);
    void setProperty(String name, Mat4& value);

    void setShader(Shader* shader);
    Shader* getShader();

  private:
    Shader* _shader = nullptr;

    GLuint getLocation(String name);
};

} // namespace Proto
#endif
