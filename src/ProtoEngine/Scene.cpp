#include "Scene.hpp"

namespace Proto {

void Scene::addChild(Node* child) { root.addChild(child); }

Node* Scene::getRoot() { return &root; }

} // namespace Proto
