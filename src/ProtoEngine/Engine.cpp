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

    Window* window = new Window{title, x, y, width, height};
    _main_window = window;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    _context = SDL_GL_CreateContext(_main_window->getSDLWindow());
    SDL_GL_SetSwapInterval(1);

    addTarget(window);

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
    glEnable(GL_SCISSOR_TEST);
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

void Engine::addTarget(Target* target) { _targets.push_back(target); }

Engine* Engine::getInstance() { return _instance; }

void Engine::render() {
    for (auto& target : _targets) {

        target->makeCurrent();

        for (auto& viewport : target->getViewports()) {
            viewport->setup();
            Camera* camera = viewport->getCamera();
            Scene* scene = viewport->getScene();

            viewport->applyBackground();
            scene->getRoot()->render(camera);
        }

        target->swapBuffers();
    }
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
