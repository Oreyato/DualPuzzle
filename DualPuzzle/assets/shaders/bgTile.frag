#version 450 core
out vec4 fragColor;
  
in vec4 vertColor;

void main()
{
    fragColor = vertColor;
}