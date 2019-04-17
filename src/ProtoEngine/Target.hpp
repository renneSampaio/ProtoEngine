#ifndef TARGET_HEADER_
#define TARGET_HEADER_

#include <vector>

#include "Viewport.hpp"

namespace Proto {

class Target {
  protected:
    std::vector<Viewport*> viewports;

  public:
    void addViewport(Viewport* viewport) { viewports.push_back(viewport); }

    std::vector<Viewport*>::const_iterator viewportsBegin() {
        return viewports.cbegin();
    }

    std::vector<Viewport*>::const_iterator viewportsEnd() {
        return viewports.cend();
    }

    virtual void makeCurrent() = 0;

    virtual ~Target(){};
};

} // namespace Proto

#endif
