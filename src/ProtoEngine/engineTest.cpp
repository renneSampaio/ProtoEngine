#include "Engine.hpp"
#include "Camera.hpp"
#include "MeshComponent.hpp"
#include "Node.hpp"
#include "Scene.hpp"
#include "Shader.hpp"

#include "SDL2/SDL.h"

using namespace Proto;

int main() {
    Engine::init("Teste", 0, 0, 400, 400);
    auto engine = Proto::Engine::getInstance();

    std::vector<Vertex> mesh{
        {glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(0.0, 0.0)}, //..
        {glm::vec3(1.0f, -1.0f, 0.0f), glm::vec2(1.0, 0.0)},  //..
        {glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0, 1.0)},   //..
        {glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec2(0.0, 1.0)}};

    std::vector<uint> indices{
        0, 1, 2, 2, 3, 0,
    };

    MeshComponent* mesh_component = new MeshComponent(mesh, indices);
    Camera cam(0.01f, 100.0f, engine->getMainWindow()->getAspectRatio(), 90.0f);

    Shader shader("shaders/test.vert", "shaders/test.frag");

    Node cameraNode;
    cameraNode.addComponent(&cam);
    cameraNode.setPosition(0.0, 0.0, 10.0);

    Node quadNode;
    quadNode.addComponent(mesh_component);
    quadNode.setShader(&shader);
    quadNode.setPosition(0.0f, 0.0f, 0.0f);

    Node quadNode2;
    quadNode2.addComponent(mesh_component);
    quadNode2.setShader(&shader);
    quadNode2.setPosition(0.0f, 0.0f, -10.0f);

    Scene scene;
    scene.addChild(&cameraNode);
    scene.addChild(&quadNode);

    Window* window = engine->getMainWindow();
    window->getViewports()[0]->setScene(&scene);
    window->getViewports()[0]->setCamera(&cam);
    window->getViewports()[0]->setClearColor(0.0, 0.4, 0.4, 1.0);

    Viewport view{10, 10, 100, 100};
    window->addViewport(&view);
    window->getViewports()[1]->setScene(&scene);
    window->getViewports()[1]->setCamera(&cam);
    window->getViewports()[1]->setClearColor(0.0, 1.0, 1.0, 1.0);

    engine->mainLoop();
}
