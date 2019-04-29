#ifndef TARGET_HEADER_
#define TARGET_HEADER_

#include <vector>

#include "Camera.hpp"
#include "Viewport.hpp"

namespace Proto {

class Target {
  protected:
    std::vector<Viewport*> viewports;
    Camera* _camera;

  public:
    void addViewport(Viewport* viewport) { viewports.push_back(viewport); }

    std::vector<Viewport*> getViewports() { return viewports; }

    int getWidth() const;
    int getHeight() const;
    int getAspectRatio() const;

    void setWidth(int new_width);
    void setHeight(int new_height);
    void setDimension(int new_width, int new_height);

    virtual void makeCurrent() = 0;
    virtual void swapBuffers() = 0;

    virtual ~Target(){};
};

} // namespace Proto

#endif
