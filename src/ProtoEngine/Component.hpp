#ifndef COMPONENT_HEADER_
#define COMPONENT_HEADER_

namespace ProtoEngine {

class Node;

class Component {
  protected:
    Node* _node;

  public:
    virtual void update() = 0;
    virtual void render() = 0;

    void setNode(Node* node) { this->_node = node; }
};

} // namespace ProtoEngine

#endif
