#define IDENT(x) x
#define XSTR(x) #x
#define STR(x) XSTR(x)
#define PATH(x, y) STR(IDENT(x)IDENT(y))
#define PATH3(p, x, y) STR(IDENT(p)IDENT(x)IDENT(y))
#define EXT .h
#define EXT_VERT .vert
#define EXT_FRAG .frag
#define EXT_TECS .tesc
#define EXT_TESE .tese
#define EXT_GEOM .geom
#define EXT_COMP .glsl
#define SHADER_PATH assets/shaders/
#define SHADER_VERT(s) PATH3(SHADER_PATH, s, EXT_VERT)
#define SHADER_FRAG(s) PATH3(SHADER_PATH, s, EXT_FRAG)
#define SHADER_TECS(s) PATH3(SHADER_PATH, s, EXT_TECS)
#define SHADER_TESE(s) PATH3(SHADER_PATH, s, EXT_TESE)
#define SHADER_GEOM(s) PATH3(SHADER_PATH, s, EXT_GEOM)
#define SHADER_COMP(s) PATH3(SHADER_PATH, s, EXT_COMP)
#define SHADER_ID(s) STR(s)

#define SCENE_NAME Scene_DualPuzzle
#define SHADER_NAME IDENT(dualpuzzle)

/**
 * Scene_030_Test 030_Test
 * 
 * Scene_Snake snake
 *  * */
