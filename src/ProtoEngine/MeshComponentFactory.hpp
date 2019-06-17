#ifndef MESH_COMPONENT_FACTORY_HEADER_
#define MESH_COMPONENT_FACTORY_HEADER_

#include "MeshComponent.hpp"

namespace Proto {

class MeshComponentFactory {
  public:
    static MeshComponent* CreateQuad(float width, float height);
    static MeshComponent* CreateCube(float width, float height, float lenght);

    static void clearAll();

  private:
    static std::vector<MeshComponent*> components;
};

} // namespace Proto

#endif
