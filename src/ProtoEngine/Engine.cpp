#include <GL/glew.h>

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "Camera.hpp"
#include "Engine.hpp"
#include "Node.hpp"
#include "Window.hpp"

namespace ProtoEngine {
Engine* Engine::instance = nullptr;

Engine::Engine(std::string title, int x, int y, int width, int height) {
    auto sdl_init_status = SDL_Init(SDL_INIT_EVERYTHING);
    if (sdl_init_status < 0) {
        std::cout << "Failed to initialize SDL. Error: " << SDL_GetError()
                  << "\n";
    }

    main_window = new Window{title, x, y, width, height};

    glewExperimental = GL_TRUE;
    GLenum glew_status = glewInit();
    if (glew_status != GLEW_OK) {
        std::cout << "Failed to initialize glew. Error:"
                  << glewGetErrorString(glew_status) << "\n";
    }

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}

Engine::~Engine() { delete main_window; }

void Engine::init(std::string title, int x, int y, int width, int height) {
    if (!instance) {
        instance = new Engine(title, x, y, width, height);
    }
}

Engine* Engine::getInstance() { return instance; }

void Engine::render() {
    glViewport(0, 0, main_window->getWidth(), main_window->getHeight());

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (!root)
        return;

    if (!camera)
        return;

    root->render(*camera);

    main_window->update();
}

void Engine::quit() { SDL_Quit(); }

} // namespace ProtoEngine