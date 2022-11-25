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
}

int Scene_DualPuzzle::getRand(int a, int b)
{
	return std::rand() % (b - a + 1) + a;
}
