#ifndef MATERIAL_HEADER_
#define MATERIAL_HEADER_

#include "ProtoTypes.hpp"

namespace Proto {

class Material {
  public:
    Material(Shader* shader);
    Material();
    virtual ~Material();

    void setProperty(const String& name, Float value);

    void setProperty(const String& name, Vec3& value);
    void setProperty(const String& name, Float x, Float y, Float z);

    void setProperty(const String& name, Vec4& value);
    void setProperty(const String& name, Float x, Float y, Float z, Float w);

    void setProperty(const String& name, Mat4& value);

    void setShader(Shader* shader);
    Shader* getShader() const;

  private:
    Shader* _shader = nullptr;

    GLuint getLocation(const String& name);
};

} // namespace Proto
#endif
