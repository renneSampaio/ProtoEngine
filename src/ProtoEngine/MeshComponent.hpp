#ifndef MESH_COMPONENT_HEADER_
#define MESH_COMPONENT_HEADER_

#include <GL/glew.h>

#include <GL/gl.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>

#include "Component.hpp"

namespace ProtoEngine {

struct Vertex {
    glm::vec3 position;
    glm::vec2 uv;
};

class MeshComponent : public Component {

  private:
    GLenum _vao;
    GLenum _vbo;
    GLenum _ebo;

  public:
    MeshComponent(std::vector<Vertex> _mesh, std::vector<uint> _indices);

    std::vector<Vertex> _mesh;
    std::vector<uint> _indices;

    void update() override;
    void render() override;
};

} // namespace ProtoEngine

#endif
