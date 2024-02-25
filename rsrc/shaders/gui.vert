#version 410
layout(location = 0) in vec3 Pos;

uniform bool NeedProjection;
uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Transform;

void main() {
    if (NeedProjection) {
        gl_Position = Projection * Transform * vec4(Pos, 1.0);
    } else {
        gl_Position = Transform * vec4(Pos, 1.0);
    }
}
