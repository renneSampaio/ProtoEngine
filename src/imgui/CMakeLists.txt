add_library(imgui imgui.cpp imgui_widgets.cpp imgui_draw.cpp imgui_demo.cpp imgui_impl_sdl imgui_impl_opengl3)
target_link_libraries(imgui GLEW GL)

