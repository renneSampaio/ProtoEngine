add_library(ProtoEngine
    Engine.cpp
    Scene.cpp
    Viewport.cpp
    IndexBuffer.cpp
    VertexBuffer.cpp
    Target.cpp
    Window.cpp
    Component.cpp
    Material.cpp
    Camera.cpp
    Node.cpp
    MeshComponent.cpp
    Shader.cpp
    )

target_link_libraries(ProtoEngine SDL2 GLEW GL SOIL)

add_executable(engineTest engineTest.cpp)
target_link_libraries(engineTest PRIVATE ProtoEngine)
