#include "MeshComponent.hpp"

#include <iostream>

namespace ProtoEngine {

MeshComponent::MeshComponent(std::vector<Vertex> mesh,
                             std::vector<uint> indices) {
    this->mesh = mesh;
    this->indices = indices;

    std::cout << this->mesh.size();
    std::cout << this->indices.size();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mesh.size(),
                 &(this->mesh[0]), GL_STATIC_DRAW);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    // Vertex texture coords
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void*)(sizeof(glm::vec3)));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * indices.size(),
                 &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void MeshComponent::update() {}

void MeshComponent::render() {
    std::cout << "Rendering mesh\n";
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
}

} // namespace ProtoEngine
