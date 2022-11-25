#ifndef Scene_DualPuzzle_H
#define Scene_DualPuzzle_H

#include "../engine/Scene.h"

// Main scene of the game, contains all the game's logic
class Scene_DualPuzzle : public Scene
{
public:
	Scene_DualPuzzle();
	virtual ~Scene_DualPuzzle();

	void load();
	void clean();
	void pause();
	void resume();
	void handleEvent(const InputState &);
	void update(float dt);
	void draw();
	void setGame(Game *);



private:
	Game *game;

	int getRand(int a, int b);
};

#endif // Scene_DualPuzzle_H
