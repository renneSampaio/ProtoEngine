#include <GL/glew.h>

#include <GL/gl.h>
#include <SDL2/SDL.h>

#include "Shader.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"
#include <SOIL/SOIL.h>
#include <iostream>

bool init();
void quit();
void render(Shader& shader);
void load_texture(const char* path, GLuint* texture);

SDL_Window* gWindow;
SDL_GLContext context;

int width = 800;
int height = 600;
ImVec4 clear_color;

GLuint vao;
GLuint vbo;
GLuint ebo;

GLuint texture_grunge;
GLuint texture_abstract;
GLuint texture_diagonal;
GLuint current_texture;

int main() {
    if (!init()) {
        return -1;
    }

    Shader shader("shaders/basic.vert", "shaders/basic.frag");

    float vertices[] = {
        -0.25f, -0.25f, 0.0f, 0.0, 0.0, //..
        0.25f,  -0.25f, 0.0f, 1.0, 0.0, //..
        0.25f,  0.25f,  0.0f, 1.0, 1.0, //..
        -0.25f, 0.25f,  0.0f, 0.0, 1.0, //..
    };

    uint indices[] = {
        0, 1, 2, 2, 3, 0,
    };

    shader.Use();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    // Vertex texture coords
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void*)(3 * sizeof(float)));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_STATIC_DRAW);

    load_texture("textures/grunge.png", &texture_grunge);
    load_texture("textures/abstract.png", &texture_abstract);
    load_texture("textures/diagonal.png", &texture_diagonal);
    current_texture = texture_diagonal;

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

        {
            ImGui::Begin("Texture Selector");

            if (ImGui::Button("Texture Grunge")) {
                current_texture = texture_grunge;
            }
            if (ImGui::Button("Texture Abstract")) {
                current_texture = texture_abstract;
            }
            if (ImGui::Button("Texture Diagonal")) {
                current_texture = texture_diagonal;
            }

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

void render(Shader& shader) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.Use();
    glBindVertexArray(vao);
    glBindTexture(GL_TEXTURE_2D, current_texture);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void load_texture(const char* path, GLuint* texture) {
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);

    int width, height, channels;
    unsigned char* image_data =
        SOIL_load_image(path, &width, &height, &channels, SOIL_LOAD_RGBA);

    if (!image_data) {
        std::cout << "Failed to load " << path << " image\n";
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, image_data);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image_data);
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

    const char* glsl_version = "#version 330";
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
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImGui_ImplSDL2_InitForOpenGL(gWindow, context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    return true;
}

void quit() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    glDeleteTextures(1, &texture_grunge);
    glDeleteTextures(1, &texture_abstract);
    glDeleteTextures(1, &texture_diagonal);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}
