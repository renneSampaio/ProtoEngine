#ifndef TARGET_HEADER_
#define TARGET_HEADER_

#include <vector>

#include "ProtoTypes.hpp"

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

    Int getWidth() const;
    Int getHeight() const;
    Float getAspectRatio() const;

    void setWidth(Int new_width);
    void setHeight(Int new_height);
    void setDimension(Int new_width, Int new_height);

    virtual void makeCurrent() = 0;
    virtual void swapBuffers() = 0;

    virtual ~Target(){};
};

} // namespace Proto

#endif
