#version 330 core 
in vec2 TexCoord;
out vec4 fColor;

void main() {
    fColor = vec4(TexCoord.x, 1.0, TexCoord.y, 1.0f);
}
