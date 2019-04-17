#ifndef VIEWPORT_HEADER_
#define VIEWPORT_HEADER_

#include <algorithm>

namespace ProtoEngine {

class Viewport {
  private:
    int _x, _y;
    int _width, _height;
    int _aspect;

    inline void updateAspectRatio() {
        this->_aspect = _width / std::max(1, _height);
    }

  public:
    Viewport(int _width, int _height);
    Viewport(int x, int y, int width, int height);

    void apply();

    inline void setHeight(int new_height) {
        this->_height = new_height;
        updateAspectRatio();
    }

    inline void setWidth(int new_width) {
        this->_width = new_width;
        updateAspectRatio();
    }

    inline int getWidth() const { return this->_width; }
    inline int getHeight() const { return this->_height; }
    inline int getAspect() const { return this->_aspect; }
};

} // namespace ProtoEngine

#endif
