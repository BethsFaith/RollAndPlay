#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 Transform;

out vec2 TexCoords;

void main()
{
    gl_Position = Transform * vec4(aPos, 1.0);
    TexCoords = aTexCoord;
}
