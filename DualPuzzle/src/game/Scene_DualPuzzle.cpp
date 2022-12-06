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

void Scene_DualPuzzle::load()
{
    std::srand((int) std::time(nullptr));

	Assets::loadShader("assets/shaders/bgTile.vert", "assets/shaders/bgTile.frag", "", "", "", "bgTile");

	shader = Assets::getShader("bgTile");

    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);

	// Prepare offsets
	Vector2 translations[100];
	int index = 0;
	float offset = 0.1f;
	for(int y = -10; y < 10; y += 2) {
		for(int x = -10; x < 10; x += 2) {
			Vector2 translation;
			translation.x = (float)x / 10.0f + offset;
			translation.y = (float)y / 10.0f + offset;
			translations[index++] = translation;
		}
	}  

	unsigned int instanceVBO;
	glGenBuffers(1, &instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector2)*100, &translations[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);	
	glVertexAttribDivisor(0, 1); // This function tells OpenGL when to update the 
							 	 // content of a vertex attribute to the next element

	// Load all textures

	// Load level from level index


}

void Scene_DualPuzzle::loadLevel(int i) {
	// Browse levels json file and get the right one


}

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

void Scene_DualPuzzle::update(float dt)
{
}

void Scene_DualPuzzle::drawBackground() {
	shader.use();
	glBindVertexArray(vao);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, 100);
	// glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Scene_DualPuzzle::draw() {
	static const GLfloat bgColor[] = {0.75f, 0.75f, 0.75f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);

	drawBackground();
}

int Scene_DualPuzzle::getRand(int a, int b)
{
	return std::rand() % (b - a + 1) + a;
}
