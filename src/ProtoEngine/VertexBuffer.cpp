#include "VertexBuffer.hpp"

namespace Proto {

VertexBuffer::VertexBuffer() { glGenBuffers(1, &_id); }

void VertexBuffer::bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); }

void VertexBuffer::unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

void VertexBuffer::setData(const std::vector<Vertex>& mesh,
                           GLenum storageUsage) {
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.size() * sizeof(Vertex),
                 &mesh[0], storageUsage);
}

} // namespace Proto
