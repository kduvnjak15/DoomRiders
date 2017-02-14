#version 330

in vec2 texCoord;

uniform sampler2D textureSampler;

out vec4 FragColor;

void main()
{
    FragColor = texture(textureSampler, texCoord);
//      FragColor = vec4(0.30f, 0.0f, 0.1f, 0.0f);

}
