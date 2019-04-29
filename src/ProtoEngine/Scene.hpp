#ifndef SCENE_HEADER_
#define SCENE_HEADER_

#include "Node.hpp"

namespace Proto {

class Scene {
  public:
    void addChild(Node* child);

    Node* getRoot();

  private:
    Node root;
};

} // namespace Proto

#endif
