#ifndef VERTEX_BUFFER_HEADER_
#define VERTEX_BUFFER_HEADER_

#include "ProtoTypes.hpp"

namespace Proto {

class VertexBuffer {
  public:
    VertexBuffer();
    virtual ~VertexBuffer();

    void bind();
    void unbind();

    void setData(const std::vector<Vertex>& mesh,
                 GLenum storageUsage = GL_STATIC_DRAW);

  private:
    GLuint _id;
};

} // namespace Proto

#endif
