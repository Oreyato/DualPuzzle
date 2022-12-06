#version 410 core

layout (location = 0) in vec2 offset;

out vec4 vertColor;

void main()
{
    const vec4 backgroundTileVerticies[6] = vec4[6] (
		vec4(-0.05f,  0.05f, 0.0f, 1.0f),
		vec4( 0.05f, -0.05f, 0.0f, 1.0f),
		vec4(-0.05f, -0.05f, 0.0f, 1.0f),

		vec4(-0.05f,  0.05f, 0.0f, 1.0f), 
     	vec4( 0.05f, -0.05f, 0.0f, 1.0f), 
     	vec4( 0.05f,  0.05f, 0.0f, 1.0f)	
    );

    gl_Position = backgroundTileVerticies[gl_VertexID] + vec4(offset, 0.0, 0.0);
    vertColor = vec4(0.35, 0.35, 0.35, 1.0);
} 