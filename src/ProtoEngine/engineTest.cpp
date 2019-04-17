#include "Engine.hpp"
#include "Camera.hpp"
#include "MeshComponent.hpp"
#include "Node.hpp"

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

    Node root;
    root.addComponent(&cam);
    root.setShader("shaders/test.vert", "shaders/test.frag");

    Node quad;
    quad.addComponent(mesh_component);
    quad.setShader("shaders/test.vert", "shaders/test.frag");
    quad.setPosition(0, 0, 10);

    root.addChild(&quad);

    engine->setRoot(&root);
    engine->setCamera(&cam);

    engine->mainLoop();
}
