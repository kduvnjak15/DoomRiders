#version 330

in vec2 texcoord;

out vec4 FragColor;

uniform sampler2D gSampler; 

void main()
{
    FragColor = texture2D(gSampler, texcoord.xy);
}
