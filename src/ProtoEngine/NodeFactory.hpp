#ifndef NODE_FACTORY_HEADER_
#define NODE_FACTORY_HEADER_

#include "Node.hpp"

namespace Proto {

class NodeFactory {
  public:
    static Node* CreateCamera(Float near = 1.0f, Float far = 1000.0f,
                              Float fovy = 90.0f);
    static Node* CreateQuad(Float width, Float height);
    static Node* CreateCube(Float width, Float height, Float lenght);

    static void clearAll();

  private:
    static std::vector<Node*> nodes;
};

} // namespace Proto
#endif
