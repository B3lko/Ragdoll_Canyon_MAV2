#pragma once
#include "Scene.h"
#include "Canyon.h"
#include "Ragdoll.h"
#include "Tree.h"
#include "Netherite.h"
#include "MyContactListener.h"
#include "Game.h"
#include "Level2.h"
#include "Menu.h"

class Level1 : public Scene {
private:

	//Mundo, gravedad y paso
	b2World* world = NULL;
	b2Vec2 gravity;
	float timeStep = 0.1;
	int velocityIterations = 8;
	int positionIterations = 8;

	Vector2i LP;

	bool isButtonRelessed = false;
	vector <Ragdoll*> rd{};

	b2Body* ground = NULL;
	Avatar* a_ground = NULL;
	Texture* tground = NULL;
	Sprite* sground = NULL;

	b2Body* roof = NULL;
	Avatar* a_roof = NULL;
	Texture* troof = NULL;
	Sprite* sroof = NULL;

	b2Body* lwall = NULL;
	Avatar* a_lwall = NULL;
	Texture* tlwall = NULL;
	Sprite* slwall = NULL;

	b2Body* rwall = NULL;
	Avatar* a_rwall = NULL;
	Texture* trwall = NULL;
	Sprite* srwall = NULL;

	Avatar* atest = NULL;
	b2Body* test = NULL;

	Canyon* canyon = nullptr;

	Sprite sBackground;
	Texture tBackground;

	Sprite sRetry;
	Texture tRetry;

	Tree* t1 = NULL;
	Netherite* n1 = NULL;

	//Contact listener
	MyContactListener* MCL = NULL;

	//Zoom
	View* view;
	bool isZoom = false;

	Sprite s_UI;
	Texture t_UI;

	Font font;
	Text winLevel, siguiente, menu, puntaje, restart, vidas, esc;
	int int_puntaje;
	bool win = false;
	bool sinvidas = false;
	bool escrelessed = true;
	bool pause = false;

public:
	Level1();
	void Update(Game& game) override;
	void Draw(RenderWindow& window) override;
};