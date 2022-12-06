#version 410 core

out vec4 vertColor;

void main()
{
    const vec4 backgroundTileVerticies[3] = vec4[3] (
		vec4(-0.05f,  0.05f, 0.0f, 1.0f),
		vec4( 0.05f, -0.05f, 0.0f, 1.0f),
		vec4(-0.05f, -0.05f, 0.0f, 1.0f)//,

		// vec4(-0.05f,  0.05f, 0.0f, 1.0f), 
     	// vec4( 0.05f, -0.05f, 0.0f, 1.0f), 
     	// vec4( 0.05f,  0.05f, 0.0f, 1.0f)	
    );

    gl_Position = backgroundTileVerticies[gl_VertexID];
    vertColor = vec4(0.0, 1.0, 0.0, 1.0);
} 