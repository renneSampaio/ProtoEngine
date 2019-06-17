#include "MeshComponentFactory.hpp"

namespace Proto {
std::vector<MeshComponent*> MeshComponentFactory::components{};

MeshComponent* MeshComponentFactory::CreateQuad(float width, float height) {

    glm::vec3 scalevec = glm::vec3(width / 2.0, height / 2.0, 1.0);

    std::vector<Vertex> mesh{
        {glm::vec3(-1.0f, -1.0f, 0.0f) * scalevec, glm::vec2(0.0, 0.0)}, //..
        {glm::vec3(1.0f, -1.0f, 0.0f) * scalevec, glm::vec2(1.0, 0.0)},  //..
        {glm::vec3(1.0f, 1.0f, 0.0f) * scalevec, glm::vec2(1.0, 1.0)},   //..
        {glm::vec3(-1.0f, 1.0f, 0.0f) * scalevec, glm::vec2(0.0, 1.0)}};

    std::vector<uint> indices{
        0, 1, 2, 2, 3, 0,
    };

    auto comp = new MeshComponent(mesh, indices);
    components.push_back(comp);

    return comp;
}

MeshComponent* MeshComponentFactory::CreateCube(float width, float height,
                                                float lenght) {

    glm::vec3 scalevec = glm::vec3(width / 2.0, height / 2.0, lenght / 2.0);

    std::vector<Vertex> mesh{
        {glm::vec3(-1.0f, -1.0f, -1.0f) * scalevec, glm::vec2(0.0, 0.0)}, //..
        {glm::vec3(1.0f, -1.0f, -1.0f) * scalevec, glm::vec2(1.0, 0.0)},  //..

        {glm::vec3(1.0f, 1.0f, -1.0f) * scalevec, glm::vec2(1.0, 1.0)}, //..
        {glm::vec3(-1.0f, 1.0f, -1.0f) * scalevec, glm::vec2(0.0, 1.0)},

        {glm::vec3(-1.0f, 1.0f, 1.0f) * scalevec, glm::vec2(0.0, 0.0)}, //..
        {glm::vec3(1.0f, 1.0f, 1.0f) * scalevec, glm::vec2(1.0, 0.0)},  //..

        {glm::vec3(1.0f, -1.0f, 1.0f) * scalevec, glm::vec2(1.0, 1.0)}, //..
        {glm::vec3(-1.0f, -1.0f, 1.0f) * scalevec, glm::vec2(0.0, 1.0)}};

    std::vector<uint> indices{0, 1, 2, // face front
                              0, 2, 3, //
                              2, 4, 3, // face top
                              2, 5, 4, //
                              1, 5, 2, // face right
                              1, 6, 5, //
                              0, 4, 7, // face left
                              0, 3, 4, //
                              5, 7, 4, // face back
                              5, 6, 7, //
                              0, 7, 6, // face bottom
                              0, 6, 1};

    auto comp = new MeshComponent(mesh, indices);
    components.push_back(comp);

    return comp;
}

void MeshComponentFactory::clearAll() {
    for (auto comp : components) {
        delete comp;
    }
};

} // namespace Proto
