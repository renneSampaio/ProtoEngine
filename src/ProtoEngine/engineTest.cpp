#include "Engine.hpp"
#include "Camera.hpp"
#include "MeshComponent.hpp"
#include "Node.hpp"

#include "SDL2/SDL.h"

using namespace ProtoEngine;

int main() {
    Engine::init("Teste", 0, 0, 400, 400);

    auto engine = ProtoEngine::Engine::get_instance();

    std::vector<Vertex> mesh{
        {glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(0.0, 0.0)}, //..
        {glm::vec3(1.0f, -1.0f, 0.0f), glm::vec2(1.0, 0.0)},  //..
        {glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0, 1.0)},   //..
        {glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec2(0.0, 1.0)}};

    std::vector<uint> indices{
        0, 1, 2, 2, 3, 0,
    };

    MeshComponent* mesh_component = new MeshComponent(mesh, indices);

    Camera cam(0.01f, 100.0f, engine->main_window->get_aspect_ratio(), 90.0f);

    Node root;
    root.add_component(&cam);
    root.set_shader("shaders/test.vert", "shaders/test.frag");

    Node quad;
    quad.add_component(mesh_component);
    quad.set_shader("shaders/test.vert", "shaders/test.frag");
    quad.position.z = 10.f;
    quad.scale = glm::vec3(10.0f);

    root.add_child(&quad);

    engine->root = &root;
    engine->camera = &cam;

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {

            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
        engine->render();
    }
    engine->quit();
}
