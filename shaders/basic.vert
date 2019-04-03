#version 330 core
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec2 vTexCoord;

out vec2 TexCoord;

uniform mat4 model;

void main() {
    gl_Position = model * vec4(vPosition, 1.0);
    TexCoord = vTexCoord;
}
