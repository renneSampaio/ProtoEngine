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
    GLenum vao;
    GLenum vbo;
    GLenum ebo;

  public:
    MeshComponent(std::vector<Vertex> mesh, std::vector<uint> indices);

    std::vector<Vertex> mesh;
    std::vector<uint> indices;

    void update() override;
    void render() override;
};

} // namespace ProtoEngine

#endif
