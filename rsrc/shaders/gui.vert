#version 330 core

layout(location = 0) in vec3 Pos;
layout (location = 1) out uvec3 gID;

uniform mat4 Transform;
uniform uvec3 ID = uvec3(0);

void main() {
    gl_Position = Transform * vec4(Pos, 1.0);
    // Сохранение идентификатора объекта
    gID = ID;
}
