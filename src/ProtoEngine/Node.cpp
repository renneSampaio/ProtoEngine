#include "Node.hpp"

#include "Camera.hpp"
#include "Component.hpp"
#include "Engine.hpp"
#include "MeshComponent.hpp"
#include "MeshComponentFactory.hpp"
#include "Shader.hpp"

#include "Material.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Proto {

Node::Node(Node* parent) : _parent(parent), _children(), _components() {
    if (_parent)
        _parent->addChild(this);
}

const Mat4& Node::getModelMatrix() const {
    _calcModel();
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

void Node::setMaterial(Material* material) { _material = material; }

void Node::render(Camera& camera) {
    if (_material) {
        _material->use();
        _material->setProperty("model", _model);
        camera.setUniforms(_material->getShader());
    }
    _calcModel();

    for (auto& comp : _components) {
        comp->render();
    }

    for (auto& child : _children) {
        child->render(camera);
    }
}

Vec3 Node::getPosition() const { return _position; }

void Node::setPosition(const Vec3& position) { _position = position; }

void Node::setPosition(Float x, Float y, Float z) {
    _position.x = x;
    _position.y = y;
    _position.z = z;
}

Vec3 Node::getRotation() const { return _rotation; }

void Node::setRotation(const Vec3& rotation) { _rotation = rotation; }

void Node::setRotation(Float x, Float y, Float z) {
    _rotation.x = x;
    _rotation.y = y;
    _rotation.z = z;
}

Vec3 Node::getScale() const { return _scale; }

void Node::setScale(const Vec3& scale) { _scale = scale; }

void Node::setScale(Float x, Float y, Float z) {
    _scale.x = x;
    _scale.y = y;
    _scale.z = z;
}

Node* Node::getParent() const { return _parent; }

void Node::setParent(Node* parent) { _parent = parent; }

void Node::_calcModel() const {
    _model = Mat4(1.0f);

    _model = glm::translate(_model, _position);
    _model =
        glm::rotate(_model, glm::radians(_rotation.x), Vec3(1.0, 0.0, 0.0));
    _model =
        glm::rotate(_model, glm::radians(_rotation.y), Vec3(0.0, 1.0, 0.0));
    _model =
        glm::rotate(_model, glm::radians(_rotation.z), Vec3(0.0, 0.0, 1.0));
    _model = glm::scale(_model, _scale);

    if (_parent != nullptr) {
        _model = _parent->getModelMatrix() * _model;
    }
}

} // namespace Proto
