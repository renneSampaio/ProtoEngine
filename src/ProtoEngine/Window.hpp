#ifndef WINDOW_HEADER_
#define WINDOW_HEADER_

#include "Target.hpp"

#include <SDL2/SDL.h>
#include <string>

namespace Proto {

class Window : public Target {
  public:
    Window();
    Window(std::string title, int x, int y, int width, int height);
    Window(std::string title, int width, int height);
    ~Window();

    void makeCurrent() override;
    void swapBuffers() override;

    SDL_Window* getSDLWindow() { return _window; }

  private:
    std::string _title;
    SDL_Window* _window;
    SDL_GLContext _contextId;
};

} // namespace Proto

#endif
