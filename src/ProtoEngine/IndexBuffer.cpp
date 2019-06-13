#include "IndexBuffer.hpp"

namespace Proto {

IndexBuffer::IndexBuffer() { glGenBuffers(1, &_id); }

void IndexBuffer::bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); }

void IndexBuffer::unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

void IndexBuffer::setData(const std::vector<Uint>& indices,
                          GLenum storageUsage) {
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Uint),
                 &indices[0], storageUsage);
}

} // namespace Proto
