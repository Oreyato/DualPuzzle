#include "Scene_DualPuzzle.h"
#include "../engine/Assets.h"
#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <ctime>


Scene_DualPuzzle::Scene_DualPuzzle()
{
}

Scene_DualPuzzle::~Scene_DualPuzzle()
{
	clean();
}

void Scene_DualPuzzle::setGame(Game *_game)
{
	game = _game;
}

#pragma region Loads
// v =============================================================╗
// v Loads                                                        ║

void Scene_DualPuzzle::loadLevel(int i) {
	// Browse levels json file and get the right one

}

void Scene_DualPuzzle::loadBackground(int width, int height) {
	Assets::loadShader("assets/shaders/bgTile.vert", "assets/shaders/bgTile.frag", "", "", "", "bgTile");
	shader = Assets::getShader("bgTile");
	glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);

	const int translationSize = width*height;
	const float squareSize = 0.05f;

	// Prepare offsets
	Vector2 translations[1000];

	int index = 0; 
	const float divider = 1/squareSize;

	for(int y = -height; y < height; y += 2) {
		for(int x = -width; x < width; x += 2) {
			Vector2 translation;

			translation.x = (float)x / divider + squareSize;
			translation.y = (float)y / divider + squareSize;

			translations[index++] = translation;
		}
	}  

	unsigned int instanceVBO;
	glGenBuffers(1, &instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector2)*translationSize, &translations[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Send translations vectors
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);	
	glVertexAttribDivisor(0, 1); // This function tells OpenGL when to update the 
							 	 // content of a vertex attribute to the next element

	shader.use();
	// Send squares size
	shader.setFloat("uniSize", squareSize);
}

void Scene_DualPuzzle::load() {
    std::srand((int) std::time(nullptr));
	
	// Load all textures

	// Load level from level index
	loadLevel(0);

	levelWidth = 19;
	levelHeight = 19;
	loadBackground(levelWidth, levelHeight);
}

// v Loads                                                        ║
// ^ =============================================================╝
#pragma endregion

void Scene_DualPuzzle::clean()
{
}

void Scene_DualPuzzle::pause()
{
}

void Scene_DualPuzzle::resume()
{
}

void Scene_DualPuzzle::handleEvent(const InputState &inputState)
{
}

#pragma region Updates
// v =============================================================╗
// v Updates                                                      ║

void Scene_DualPuzzle::update(float dt)
{

}

// v Updates                                                      ║
// ^ =============================================================╝
#pragma endregion
#pragma region Draws
// v =============================================================╗
// v Draws                                                        ║

void Scene_DualPuzzle::drawBackground() {
	shader.use();

	glBindVertexArray(vao);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, levelWidth*levelHeight);
	// glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Scene_DualPuzzle::draw() {
	static const GLfloat bgColor[] = {0.75f, 0.75f, 0.75f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);

	drawBackground();
}

// v Draws                                                        ║
// ^ =============================================================╝
#pragma endregion

int Scene_DualPuzzle::getRand(int a, int b)
{
	return std::rand() % (b - a + 1) + a;
}
