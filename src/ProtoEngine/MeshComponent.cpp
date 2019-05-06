#include "MeshComponent.hpp"

#include <iostream>

namespace Proto {

MeshComponent::MeshComponent(std::vector<Vertex> mesh,
                             std::vector<uint> indices) {
    this->_mesh = mesh;
    this->_indices = indices;

    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mesh.size(),
                 &(this->_mesh[0]), GL_STATIC_DRAW);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    // Vertex texture coords
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void*)(sizeof(glm::vec3)));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * indices.size(),
                 &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void MeshComponent::update() {}

void MeshComponent::render() {
    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, nullptr);
}

MeshComponent* MeshComponentFactory::CreateQuad(int width, int height) {

    glm::vec3 scalevec = glm::vec3(width / 2.0, height / 2.0, 1.0);

    std::vector<Vertex> mesh{
        {glm::vec3(-1.0f, -1.0f, 0.0f) * scalevec, glm::vec2(0.0, 0.0)}, //..
        {glm::vec3(1.0f, -1.0f, 0.0f) * scalevec, glm::vec2(1.0, 0.0)},  //..
        {glm::vec3(1.0f, 1.0f, 0.0f) * scalevec, glm::vec2(1.0, 1.0)},   //..
        {glm::vec3(-1.0f, 1.0f, 0.0f) * scalevec, glm::vec2(0.0, 1.0)}};

    std::vector<uint> indices{
        0, 1, 2, 2, 3, 0,
    };

    return new MeshComponent(mesh, indices);
}

MeshComponent* MeshComponentFactory::CreateCube(int width, int height,
                                                int lenght) {

    glm::vec3 scalevec = glm::vec3(width / 2.0, height / 2.0, lenght / 2.0);

    std::vector<Vertex> mesh{
        {glm::vec3(-1.0f, -1.0f, -1.0f) * scalevec, glm::vec2(0.0, 0.0)}, //..
        {glm::vec3(1.0f, -1.0f, -1.0f) * scalevec, glm::vec2(1.0, 0.0)},  //..

        {glm::vec3(1.0f, 1.0f, -1.0f) * scalevec, glm::vec2(1.0, 1.0)}, //..
        {glm::vec3(-1.0f, 1.0f, -1.0f) * scalevec, glm::vec2(0.0, 1.0)},

        {glm::vec3(-1.0f, 1.0f, 1.0f) * scalevec, glm::vec2(0.0, 0.0)}, //..
        {glm::vec3(1.0f, 1.0f, 0.0f) * scalevec, glm::vec2(1.0, 0.0)},  //..

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
    return new MeshComponent(mesh, indices);
};

} // namespace Proto
