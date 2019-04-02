add_subdirectory(imgui)

add_library(shader Shader.cpp)
target_link_libraries(shader GLEW GL)

add_executable(main main.cpp )
target_link_libraries(main PRIVATE shader imgui SDL2 GLEW GL SOIL)

