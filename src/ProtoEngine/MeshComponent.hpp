#ifndef MESH_COMPONENT_HEADER_
#define MESH_COMPONENT_HEADER_

#include <GL/glew.h>

#include <GL/gl.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>

#include "ProtoTypes.hpp"

#include "Component.hpp"

namespace Proto {

class MeshComponent : public Component {
  public:
    MeshComponent(std::vector<Vertex> _mesh, std::vector<uint> _indices);
    virtual ~MeshComponent(){};

    std::vector<Vertex> _mesh;
    std::vector<uint> _indices;

    void update() override;
    void render() override;

  private:
    GLenum _vao;
    GLenum _vbo;
    GLenum _ebo;
};

} // namespace Proto

#endif
