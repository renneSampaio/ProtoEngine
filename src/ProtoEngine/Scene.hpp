#ifndef SCENE_HEADER_
#define SCENE_HEADER_

#include "Node.hpp"

namespace Proto {

class Scene {
  public:
    Node* getRoot();

  private:
    Node root;
};

} // namespace Proto

#endif
