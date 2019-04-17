#ifndef ENGINE_HEADER_
#define ENGINE_HEADER_

#include <string>

#include "Window.hpp"

namespace Proto {

class Node;
class Camera;

class Engine {
  private:
  public:
    static void init(std::string title, int x, int y, int width, int height);
    static void quit();

    static Engine* getInstance();

    void render();

    ~Engine();

    Node* getRoot() const;
    void setRoot(Node* root);

    Camera* getCamera() const;
    void setCamera(Camera* camera);

    Window* getMainWindow() const;
    void setMainWindow(Window* main_window);

    void mainLoop();

  private:
    Engine(std::string title, int x, int y, int width, int height);

    static Engine* _instance;

    Node* _root;
    Camera* _camera;
    Window* _main_window;
};

} // namespace Proto

#endif
