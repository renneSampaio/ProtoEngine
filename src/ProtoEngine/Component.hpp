#ifndef COMPONENT_HEADER_
#define COMPONENT_HEADER_

namespace ProtoEngine {

class Node;

class Component {
  protected:
    Node* node;

  public:
    virtual void update() = 0;
    virtual void render() = 0;

    void set_node(Node* node) { this->node = node; }
};

} // namespace ProtoEngine

#endif
