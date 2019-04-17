#ifndef ENGINE_HEADER_
#define ENGINE_HEADER_

#include <string>

#include "Window.hpp"

namespace ProtoEngine {

class Node;
class Camera;

class Engine {
  private:
    static Engine* instance;

    Engine(std::string title, int x, int y, int width, int height);

  public:
    Node* root;
    Camera* camera;
    Window* main_window;

    static void init(std::string title, int x, int y, int width, int height);
    static void quit();

    static Engine* getInstance();

    void render();

    ~Engine();
};

} // namespace ProtoEngine

#endif
