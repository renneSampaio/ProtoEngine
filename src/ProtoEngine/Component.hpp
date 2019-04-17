#ifndef COMPONENT_HEADER_
#define COMPONENT_HEADER_

namespace Proto {

class Node;

class Component {
  public:
    virtual void update() = 0;
    virtual void render() = 0;

    void setNode(Node* node) { this->_node = node; }
    Node* getNode() { return _node; }

  private:
    Node* _node;
};

} // namespace Proto

#endif
