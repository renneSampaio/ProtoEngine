#ifndef NODE_HEADER_
#define NODE_HEADER_

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <string>
#include <vector>

#include "ProtoTypes.hpp"

namespace Proto {

class Shader;
class Material;
class Camera;
class Component;

class Node {
  public:
    Node(Node* parent = nullptr);

    const Mat4& getModelMatrix() const;

    void addChild(Node* child);
    void addComponent(Component* component);

    void setMaterial(Material* material);

    void render(Camera& camera);

    Vec3 getPosition() const;
    void setPosition(const Vec3& position);
    void setPosition(Float x, Float y, Float z);

    Vec3 getRotation() const;
    void setRotation(const Vec3& rotation);
    void setRotation(Float x, Float y, Float z);

    Vec3 getScale() const;
    void setScale(const Vec3& scale);
    void setScale(Float x, Float y, Float z);

    Node* getParent() const;
    void setParent(Node* parent);

  private:
    void _calcModel() const;

    Vec3 _position = Vec3(0.0);
    Vec3 _rotation = Vec3(0.0);
    Vec3 _scale = Vec3(1.0f);

    // mutable to override constness in method
    mutable Mat4 _model = Mat4(1.0f);

    Node* _parent = nullptr;
    std::vector<Node*> _children;
    std::vector<Component*> _components;

    Material* _material = nullptr;
};

class NodeFactory {
  public:
    static Node* CreateCamera(Float near = 1.0f, Float far = 1000.0f,
                              Float fovy = 90.0f);
    static Node* CreateQuad(Float width, Float height);
    static Node* CreateCube(Float width, Float height, Float lenght);
};

} // namespace Proto

#endif
