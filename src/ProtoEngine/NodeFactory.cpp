#include "NodeFactory.hpp"

#include "Camera.hpp"
#include "MeshComponentFactory.hpp"

namespace Proto {

std::vector<Node*> NodeFactory::nodes{};

Node* NodeFactory::CreateCamera(Float near, Float far, Float fovy) {
    Node* cameraNode = new Node();
    Camera* cam = new Camera(near, far, fovy);
    cameraNode->addComponent(cam);

    return cameraNode;
}

Node* NodeFactory::CreateQuad(Float width, Float height) {
    Node* quadNode = new Node();
    quadNode->addComponent(MeshComponentFactory::CreateQuad(width, height));
    quadNode->setPosition(0.0f, 0.0f, 0.0f);

    return quadNode;
}

Node* NodeFactory::CreateCube(Float width, Float height, Float lenght) {
    Node* cubeNode = new Node();
    cubeNode->addComponent(
        MeshComponentFactory::CreateCube(width, height, lenght));
    cubeNode->setPosition(0.0f, 0.0f, 0.0f);

    return cubeNode;
}

void NodeFactory::clearAll() {
    for (auto node : nodes) {
        delete node;
    }
}

} // namespace Proto
