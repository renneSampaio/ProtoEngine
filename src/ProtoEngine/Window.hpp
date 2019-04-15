#ifndef WINDOW_HEADER_
#define WINDOW_HEADER_

#include "Target.hpp"

#include <SDL2/SDL.h>
#include <string>

namespace ProtoEngine {

class Window : public Target {
  private:
    std::string title;
    SDL_Window* window;
    SDL_GLContext context_id;

  public:
    Window();
    Window(std::string title, int x, int y, int width, int height);
    Window(std::string title, int width, int height);
    ~Window();

    int get_width() const;
    int get_height() const;
    int get_aspect_ratio() const;

    void set_width(int new_width);
    void set_height(int new_height);
    void set_dimension(int new_width, int new_height);

    void make_current() override;
    void update();
};

} // namespace ProtoEngine

#endif
