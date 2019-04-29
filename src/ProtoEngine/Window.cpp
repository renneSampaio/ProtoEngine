#include <iostream>

#include "Engine.hpp"
#include "Window.hpp"

namespace Proto {

Window::Window(std::string title, int x, int y, int width, int height) {
    this->_window =
        SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);

    if (!this->_window) {
        std::cout << "Failed to create window { " << title << "\n";
        std::cout << " -- Error: " << SDL_GetError() << "\n";
    }

    viewports.push_back(new Viewport(x, y, width, height));
}

Window::Window(std::string title, int width, int height)
    : Window(title, 0, 0, width, height) {}

Window::Window() : Window("ProtoEngine", 0, 0, 400, 400) {}

Window::~Window() {
    SDL_GL_DeleteContext(_contextId);
    SDL_DestroyWindow(_window);
}

void Window::makeCurrent() {
    SDL_GL_MakeCurrent(this->_window, Engine::getInstance()->getContext());
}

void Window::swapBuffers() { SDL_GL_SwapWindow(_window); }

} // namespace Proto
