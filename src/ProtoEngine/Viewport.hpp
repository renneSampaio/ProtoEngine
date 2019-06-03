#ifndef VIEWPORT_HEADER_
#define VIEWPORT_HEADER_

#include "Camera.hpp"
#include "Scene.hpp"
#include <algorithm>

#include "ProtoTypes.hpp"

namespace Proto {

class Viewport {
  public:
    Viewport(Int _width, Int _height);
    Viewport(Int x, Int y, Int width, Int height);

    void setup();
    void applyBackground();

    inline int getHeight() const { return this->_height; }
    inline void setHeight(Int new_height) {
        this->_height = new_height;
        updateAspectRatio();
    }

    inline Int getWidth() const { return this->_width; }
    inline void setWidth(Int new_width) {
        this->_width = new_width;
        updateAspectRatio();
    }

    inline Float getAspect() const { return this->_aspect; }

    void setClearColor(Float r, Float g, Float b, Float a);

    void setScene(Scene* scene);
    Scene* getScene();

    void setCamera(Camera* camera);
    Camera* getCamera();

  private:
    Int _x, _y;
    Int _width, _height;
    Float _aspect;

    Vec4 _clearColor;

    Camera* _camera;
    Scene* _scene;

    inline void updateAspectRatio() {
        this->_aspect = ((Float)_width) / std::max(1, _height);
    }
};

} // namespace Proto

#endif
