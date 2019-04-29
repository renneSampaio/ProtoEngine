#include "Node.hpp"

#include "Camera.hpp"
#include "Component.hpp"
#include "Shader.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Proto {

Node::Node() : _parent(nullptr) {}
Node::Node(Node* parent) : _parent(parent) { _parent->addChild(this); }

glm::mat4 Node::getModel() {
    calcModel();
    return _model;
}

void Node::addChild(Node* child) {
    child->setParent(this);
    _children.push_back(child);
}

void Node::addComponent(Component* component) {
    component->setNode(this);
    _components.push_back(component);
}

void Node::setShader(Shader* shader) { _shader = shader; }

void Node::render(Camera* camera) {
    if (_shader) {
        _shader->Use();

        GLuint modelLoc = glGetUniformLocation(_shader->program(), "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(_model));

        camera->setUniforms(_shader);
    }

    calcModel();

    for (auto& comp : _components) {
        comp->render();
    }

    for (auto& child : _children) {
        child->render(camera);
    }
}

glm::vec3 Node::getPosition() const { return _position; }

void Node::setPosition(const glm::vec3& position) { _position = position; }

void Node::setPosition(float x, float y, float z) {
    _position.x = x;
    _position.y = y;
    _position.z = z;
}

glm::vec3 Node::getRotation() const { return _rotation; }

void Node::setRotation(const glm::vec3& rotation) { _rotation = rotation; }

void Node::setRotation(float x, float y, float z) {
    _rotation.x = x;
    _rotation.y = y;
    _rotation.z = z;
}

glm::vec3 Node::getScale() const { return _scale; }

void Node::setScale(const glm::vec3& scale) { _scale = scale; }

void Node::setScale(float x, float y, float z) {
    _scale.x = x;
    _scale.y = y;
    _scale.z = z;
}

Node* Node::getParent() const { return _parent; }

void Node::setParent(Node* parent) { _parent = parent; }

void Node::calcModel() {
    _model = glm::mat4(1.0f);

    _model = glm::translate(_model, _position);
    _model = glm::rotate(_model, glm::radians(_rotation.x),
                         glm::vec3(1.0, 0.0, 0.0));
    _model = glm::rotate(_model, glm::radians(_rotation.y),
                         glm::vec3(0.0, 1.0, 0.0));
    _model = glm::rotate(_model, glm::radians(_rotation.z),
                         glm::vec3(0.0, 0.0, 1.0));
    _model = glm::scale(_model, _scale);

    if (_parent != nullptr) {
        _model = _parent->getModel() * _model;
    }
}

} // namespace Proto
