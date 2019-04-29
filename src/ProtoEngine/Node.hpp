#ifndef NODE_HEADER_
#define NODE_HEADER_

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <string>
#include <vector>

namespace Proto {

class Shader;
class Camera;

class Component;

class Node {
  public:
    Node();
    Node(Node* parent);

    glm::mat4 getModel();

    void addChild(Node* child);
    void addComponent(Component* component);

    void setShader(Shader* shader);

    void render(Camera* camera);

    glm::vec3 getPosition() const;
    void setPosition(const glm::vec3& position);
    void setPosition(float x, float y, float z);

    glm::vec3 getRotation() const;
    void setRotation(const glm::vec3& rotation);
    void setRotation(float x, float y, float z);

    glm::vec3 getScale() const;
    void setScale(const glm::vec3& scale);
    void setScale(float x, float y, float z);

    Node* getParent() const;
    void setParent(Node* parent);

  private:
    void calcModel();

    glm::vec3 _position = glm::vec3(0.0);
    glm::vec3 _rotation = glm::vec3(0.0);
    glm::vec3 _scale = glm::vec3(1.0f);

    glm::mat4 _model;

    Node* _parent = nullptr;
    std::vector<Node*> _children;
    std::vector<Component*> _components;

    Shader* _shader;
};

} // namespace Proto

#endif
