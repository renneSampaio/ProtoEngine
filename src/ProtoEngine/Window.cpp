#include <iostream>

#include "Window.hpp"

namespace Proto {

Window::Window(std::string title, int x, int y, int width, int height) {
    this->_window =
        SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);

    if (!this->_window) {
        std::cout << "Failed to create window { " << title << "\n";
        std::cout << " -- Error: " << SDL_GetError() << "\n";
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    _contextId = SDL_GL_CreateContext(_window);
    SDL_GL_SetSwapInterval(1);

    viewports.push_back(new Viewport(x, y, width, height));
}

Window::Window(std::string title, int width, int height)
    : Window(title, 0, 0, width, height) {}

Window::Window() : Window("ProtoEngine", 0, 0, 400, 400) {}

Window::~Window() {
    SDL_GL_DeleteContext(_contextId);
    SDL_DestroyWindow(_window);
}

int Window::getWidth() const { return viewports[0]->getWidth(); }
int Window::getHeight() const { return viewports[0]->getHeight(); };
int Window::getAspectRatio() const { return viewports[0]->getAspect(); };

void Window::setWidth(int new_width) { viewports[0]->setWidth(new_width); }

void Window::setHeight(int new_height) { viewports[0]->setHeight(new_height); }

void Window::setDimension(int new_width, int new_height) {
    viewports[0]->setWidth(new_width);
    viewports[0]->setHeight(new_height);
}

void Window::makeCurrent() {
    SDL_GL_MakeCurrent(this->_window, this->_contextId);
}

void Window::update() { SDL_GL_SwapWindow(_window); }

} // namespace Proto
