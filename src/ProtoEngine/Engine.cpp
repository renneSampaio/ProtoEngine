#include <GL/glew.h>

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "Camera.hpp"
#include "Engine.hpp"
#include "Node.hpp"
#include "Window.hpp"

namespace Proto {
Engine* Engine::_instance = nullptr;

Engine::Engine(std::string title, int x, int y, int width, int height) {
    auto sdl_init_status = SDL_Init(SDL_INIT_EVERYTHING);
    if (sdl_init_status < 0) {
        std::cout << "Failed to initialize SDL. Error: " << SDL_GetError()
                  << "\n";
    }

    _main_window = new Window{title, x, y, width, height};

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

Engine::~Engine() { delete _main_window; }

Node* Engine::getRoot() const { return _root; }

void Engine::setRoot(Node* root) { _root = root; }

Camera* Engine::getCamera() const { return _camera; }

void Engine::setCamera(Camera* camera) { _camera = camera; }

Window* Engine::getMainWindow() const { return _main_window; }

void Engine::setMainWindow(Window* main_window) { _main_window = main_window; }

void Engine::init(std::string title, int x, int y, int width, int height) {
    if (!_instance) {
        _instance = new Engine(title, x, y, width, height);
    }
}

Engine* Engine::getInstance() { return _instance; }

void Engine::render() {
    glViewport(0, 0, _main_window->getWidth(), _main_window->getHeight());

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (!_root)
        return;

    if (!_camera)
        return;

    _root->render(*_camera);

    _main_window->update();
}

void Engine::mainLoop() {

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {

            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
        render();
    }
    quit();
}

void Engine::quit() { SDL_Quit(); }

} // namespace Proto
