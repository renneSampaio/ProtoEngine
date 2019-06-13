#ifndef INDEX_BUFFER_HEADER_
#define INDEX_BUFFER_HEADER_

#include "ProtoTypes.hpp"

namespace Proto {

class IndexBuffer {
  public:
    IndexBuffer();
    virtual ~IndexBuffer();

    void bind();
    void unbind();

    void setData(const std::vector<Uint>& indices,
                 GLenum storageUsage = GL_STATIC_DRAW);

  private:
    GLuint _id;
};

} // namespace Proto

#endif
