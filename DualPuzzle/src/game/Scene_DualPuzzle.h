#ifndef Scene_DualPuzzle_H
#define Scene_DualPuzzle_H

#include "../engine/Scene.h"
#include "../engine/components/Actor.h"

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

	void loadLevel(int i);

private:
	Game *game;
	GLuint vao;
    Shader shader;
    float timeSinceStart;

	int getRand(int a, int b);

	void loadBackground(int width, int height);
	void drawBackground();

	//v Actors =======================================================
	std::vector<Actor*> actors; 

	void addActor(Actor* actorP);
	void removeActor(Actor* actorP);
	//^ Actors =======================================================
	//v Level init values ============================================
	// Level
	int levelWidth;
	int levelHeight;
	// Tile bgTiles; <- pas besoin, seront dessinées au début du draw()

	// Players
	// Player players
	// Player A
	int plAStartXPos;
	int plAStartYPos;
	// Player B
	int plBStartXPos;
	int plBStartYPos;

	// End tiles
	// Endtile endTiles
	// End A
	int plAEndXPos;
	int plAEndYPos;
	// End B
	int plBEndXPos;
	int plBEndYPos;
	//^ Level init values ============================================
};

#endif // Scene_DualPuzzle_H
