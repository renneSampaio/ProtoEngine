#ifndef WINDOW_HEADER_
#define WINDOW_HEADER_

#include "Target.hpp"

#include <SDL2/SDL.h>
#include <string>

namespace ProtoEngine {

class Window : public Target {
  private:
    std::string _title;
    SDL_Window* _window;
    SDL_GLContext _contextId;

  public:
    Window();
    Window(std::string title, int x, int y, int width, int height);
    Window(std::string title, int width, int height);
    ~Window();

    int getWidth() const;
    int getHeight() const;
    int getAspectRatio() const;

    void setWidth(int new_width);
    void setHeight(int new_height);
    void setDimension(int new_width, int new_height);

    void makeCurrent() override;
    void update();
};

} // namespace ProtoEngine

#endif
