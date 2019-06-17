#include "Material.hpp"

namespace Proto {

Material::Material() {}

Material::Material(Shader* shader) : _shader(shader) {}

void Material::setProperty(const String& name, Float value) {
    glUniform1f(getLocation(name), value);
}
void Material::setProperty(const String& name, Mat4& value) {
    glUniformMatrix4fv(getLocation(name), 1, GL_FALSE, glm::value_ptr(value));
}

void Material::setShader(Shader* shader) { _shader = shader; }

Shader* Material::getShader() const { return _shader; }

void Material::use() {
    if (_shader)
        _shader->Use();
};

void Material::setProperty(const String& name, Vec3& value) {
    glUniform3fv(getLocation(name), 1, glm::value_ptr(value));
}

void Material::setProperty(const String& name, Float x, Float y, Float z) {
    glUniform3f(getLocation(name), x, y, z);
}

void Material::setProperty(const String& name, Float x, Float y, Float z,
                           Float w) {
    glUniform4f(getLocation(name), x, y, z, w);
}

void Material::setProperty(const String& name, Vec4& value) {
    glUniform4fv(getLocation(name), 1, glm::value_ptr(value));
}

GLuint Material::getLocation(const String& name) {
    if (_shader) {
        return glGetUniformLocation(_shader->program(), name.c_str());
    }
    return -1;
}

} // namespace Proto
