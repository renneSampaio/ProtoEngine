#include <GL/glew.h>

#include <GL/gl.h>
#include <SDL2/SDL.h>

#include "Shader.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"
#include <iostream>

bool init();
void quit();
void render(Shader &shader);

SDL_Window *gWindow;
SDL_GLContext context;

int width = 800;
int height = 600;
ImVec4 clear_color;

GLuint vao;
GLuint vbo;

int main() {
    if (!init()) {
        return -1;
    }

    Shader shader("shaders/basic.vert", "shaders/basic.frag");

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, //..
        0.5f,  -0.5f, 0.0f, //..
        0.0f,  0.5f,  0.0f,
    };

    shader.Use();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

    bool show_demo_window = false;
    bool show_another_window = false;
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            ImGui_ImplSDL2_ProcessEvent(&e);

            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(gWindow);
        ImGui::NewFrame();

        if (show_demo_window) {
            ImGui::ShowDemoWindow(&show_demo_window);
        }
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello,
                                           // world!" and append into it.

            ImGui::Text(
                "This is some useful text."); // Display some text (you can
                                              // use a format strings too)
            ImGui::Checkbox("Demo Window",
                            &show_demo_window); // Edit bools storing our
                                                // window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat(
                "float", &f, 0.0f,
                1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3(
                "clear color",
                (float *)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button(
                    "Button")) // Buttons return true when clicked (most
                               // widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                        1000.0f / ImGui::GetIO().Framerate,
                        ImGui::GetIO().Framerate);
            ImGui::End();
        }

        ImGui::Render();
        render(shader);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(gWindow);
    }

    quit();
    return 0;
}

void render(Shader &shader) {
    glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.Use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

bool init() {
    auto sdl_init_status = SDL_Init(SDL_INIT_EVERYTHING);
    if (sdl_init_status < 0) {
        std::cout << "Failed to initialize SDL. Error: " << SDL_GetError()
                  << "\n";
        return false;
    }

    gWindow =
        SDL_CreateWindow("Demo 01", 0, 0, width, height, SDL_WINDOW_OPENGL);

    if (gWindow == nullptr) {
        std::cout << "Failed to initialize window. Error: " << SDL_GetError()
                  << "\n";
        return false;
    }

    const char *glsl_version = "#version 330";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    context = SDL_GL_CreateContext(gWindow);

    glewExperimental = GL_TRUE;
    GLenum glew_status = glewInit();
    if (glew_status != GLEW_OK) {
        std::cout << "Failed to initialize glew. Error:"
                  << glewGetErrorString(glew_status) << "\n";
        return false;
    }

    glViewport(0, 0, width, height);

    // Make buffer swap sync to monitor refresh
    SDL_GL_SetSwapInterval(1);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplSDL2_InitForOpenGL(gWindow, context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    return true;
}

void quit() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}
