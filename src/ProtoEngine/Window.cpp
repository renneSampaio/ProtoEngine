#include <iostream>

#include "Window.hpp"

namespace ProtoEngine {

Window::Window(std::string title, int x, int y, int width, int height) {
    this->window =
        SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);

    if (!this->window) {
        std::cout << "Failed to create window { " << title << "\n";
        std::cout << " -- Error: " << SDL_GetError() << "\n";
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    context_id = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1);

    viewports.push_back(new Viewport(x, y, width, height));
}

Window::Window(std::string title, int width, int height)
    : Window(title, 0, 0, width, height) {}

Window::Window() : Window("ProtoEngine", 0, 0, 400, 400) {}

Window::~Window() {
    SDL_GL_DeleteContext(context_id);
    SDL_DestroyWindow(window);
}

int Window::get_width() const { return viewports[0]->get_width(); }
int Window::get_height() const { return viewports[0]->get_height(); };
int Window::get_aspect_ratio() const { return viewports[0]->get_aspect(); };

void Window::set_width(int new_width) { viewports[0]->set_width(new_width); }

void Window::set_height(int new_height) {
    viewports[0]->set_height(new_height);
}

void Window::set_dimension(int new_width, int new_height) {
    viewports[0]->set_width(new_width);
    viewports[0]->set_height(new_height);
}

void Window::make_current() {
    SDL_GL_MakeCurrent(this->window, this->context_id);
}

void Window::update() { SDL_GL_SwapWindow(window); }

} // namespace ProtoEngine
