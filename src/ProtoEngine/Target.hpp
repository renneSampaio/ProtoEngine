#ifndef TARGET_HEADER_
#define TARGET_HEADER_

#include <vector>

#include "Viewport.hpp"

namespace ProtoEngine {

class Target {
  protected:
    std::vector<Viewport*> viewports;

  public:
    void add_viewport(Viewport* viewport) { viewports.push_back(viewport); }

    std::vector<Viewport*>::const_iterator viewports_begin() {
        return viewports.cbegin();
    }

    std::vector<Viewport*>::const_iterator viewports_end() {
        return viewports.cend();
    }

    virtual void make_current() = 0;

    virtual ~Target(){};
};

} // namespace ProtoEngine

#endif
