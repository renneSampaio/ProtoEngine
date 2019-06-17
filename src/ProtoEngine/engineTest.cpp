#include "Engine.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include "MeshComponent.hpp"
#include "Node.hpp"
#include "NodeFactory.hpp"
#include "Scene.hpp"
#include "Shader.hpp"

#include "SDL2/SDL.h"

using namespace Proto;

int main() {
    Engine::init("Teste", 0, 0, 600, 400);
    auto engine = Proto::Engine::getInstance();

    Camera cam(0.01f, 100.0f, 90.0f);

    Shader shader("shaders/default.vert", "shaders/default.frag");
    Material mat(&shader);

    Node cameraNode;
    cameraNode.addComponent(&cam);
    cameraNode.setPosition(0.0, 0.0, 10.0);

    Node* quadNode = NodeFactory::CreateQuad(5.0f, 5.0f);
    quadNode->setPosition(0, 3, 0);
    quadNode->setRotation(0, 45, 0);
    quadNode->setMaterial(&mat);

    Node* cubeNode = NodeFactory::CreateCube(5, 5, 5);
    cubeNode->setPosition(0, -3, 0);
    cubeNode->setRotation(45, 45, 0);
    cubeNode->setMaterial(&mat);

    Scene scene;
    scene.getRoot()->addChild(&cameraNode);
    scene.getRoot()->addChild(quadNode);
    scene.getRoot()->addChild(cubeNode);

    Window* window = engine->getMainWindow();
    window->getViewports()[0]->setScene(&scene);
    window->getViewports()[0]->setCamera(&cam);
    window->getViewports()[0]->setClearColor(0.0, 0.4, 0.4, 1.0);

    engine->mainLoop();
    engine->quit();
}
