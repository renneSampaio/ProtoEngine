#version 330 core 
in vec2 TexCoord;
out vec4 fColor;

uniform sampler2D Texture;

void main() {
    fColor = texture(Texture, TexCoord);
}
