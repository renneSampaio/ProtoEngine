#ifndef VIEWPORT_HEADER_
#define VIEWPORT_HEADER_

#include <algorithm>

namespace ProtoEngine {

class Viewport {
  private:
    int x, y;
    int width, height;
    int aspect;

    inline void update_aspect_ratio() {
        this->aspect = width / std::max(1, height);
    }

  public:
    Viewport(int width, int height);
    Viewport(int x, int y, int width, int height);

    void apply();

    inline void setHeight(int new_height) {
        this->height = new_height;
        update_aspect_ratio();
    }

    inline void setWidth(int new_width) {
        this->width = new_width;
        update_aspect_ratio();
    }

    inline int getWidth() const { return this->width; }
    inline int getHeight() const { return this->height; }
    inline int getAspect() const { return this->aspect; }
};

} // namespace ProtoEngine

#endif
