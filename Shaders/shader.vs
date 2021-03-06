#version 330

layout (location = 0) in vec3 Position;
layout (location = 0) in vec2 TexCoord; 

uniform mat4 gWorld;

out vec2 texcoord; 

void main()
{
    gl_Position = gWorld * vec4(Position, 1.0);
    texcoord = TexCoord; 
}
