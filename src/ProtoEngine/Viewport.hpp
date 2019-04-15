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

    inline void set_height(int new_height) {
        this->height = new_height;
        update_aspect_ratio();
    }

    inline void set_width(int new_width) {
        this->width = new_width;
        update_aspect_ratio();
    }

    inline int get_width() const { return this->width; }
    inline int get_height() const { return this->height; }
    inline int get_aspect() const { return this->aspect; }
};

} // namespace ProtoEngine

#endif
