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

	const vec4 verticiesColor[6] = vec4[6] (
		vec4( 0.45f, 0.45f, 0.45f, 1.0f),
		vec4( 0.90f, 0.90f, 0.90f, 1.0f),
		vec4( 0.55f, 0.55f, 0.55f, 1.0f),

		vec4( 0.45f, 0.45f, 0.45f, 1.0f), 
     	vec4( 0.90f, 0.90f, 0.90f, 1.0f), 
     	vec4( 0.55f, 0.55f, 0.55f, 1.0f)	
    );
	// 	const vec4 verticiesColor[6] = vec4[6] (
	// 	vec4( 0.f, 0.f, 0.f, 1.0f),
	// 	vec4( 0.f, 0.99f, 0.f, 1.0f),
	// 	vec4( 0.f, 0.f, 0.99f, 1.0f),

	// 	vec4( 0.99f, 0.f, 0.f, 1.0f), 
    //  	vec4( 0.f, 0.99f, 0.f, 1.0f), 
    //  	vec4( 0.f, 0.f, 0.99f, 1.0f)	
    // );
    vertColor = verticiesColor[gl_VertexID];
} 