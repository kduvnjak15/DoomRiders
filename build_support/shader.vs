#version 330


layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 textureCoord;

uniform mat4 gWorld;

out vec2 texCoord;

void main()
{
    gl_Position = gWorld * vec4(Position, 1.0);
    //color = vec4(clamp(Position, 0.0, 1.0), 1.0f);
    texCoord = textureCoord;
}
