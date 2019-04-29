#ifndef VIEWPORT_HEADER_
#define VIEWPORT_HEADER_

#include "Camera.hpp"
#include "Scene.hpp"
#include <algorithm>

namespace Proto {

class Viewport {
  public:
    Viewport(int _width, int _height);
    Viewport(int x, int y, int width, int height);

    void setup();
    void applyBackground();

    inline int getHeight() const { return this->_height; }
    inline void setHeight(int new_height) {
        this->_height = new_height;
        updateAspectRatio();
    }

    inline int getWidth() const { return this->_width; }
    inline void setWidth(int new_width) {
        this->_width = new_width;
        updateAspectRatio();
    }

    inline int getAspect() const { return this->_aspect; }

    void setClearColor(float r, float g, float b, float a);

    void setScene(Scene* scene);
    Scene* getScene();

    void setCamera(Camera* camera);
    Camera* getCamera();

  private:
    int _x, _y;
    int _width, _height;
    int _aspect;

    glm::vec4 _clearColor;

    Camera* _camera;
    Scene* _scene;

    inline void updateAspectRatio() {
        this->_aspect = _width / std::max(1, _height);
    }
};

} // namespace Proto

#endif
