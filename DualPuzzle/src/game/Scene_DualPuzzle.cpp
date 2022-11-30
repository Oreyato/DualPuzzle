#include "Scene_DualPuzzle.h"
#include "../engine/Assets.h"

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

void Scene_DualPuzzle::draw() {
	// Draw background
	// glDrawArraysInstanced(GL_RECTANGLE, 0, 6, 1024 * 1024);

	
}

int Scene_DualPuzzle::getRand(int a, int b)
{
	return std::rand() % (b - a + 1) + a;
}
