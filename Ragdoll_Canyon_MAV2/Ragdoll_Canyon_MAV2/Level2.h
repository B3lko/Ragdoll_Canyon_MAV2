#pragma once
#include "Scene.h"
#include "Canyon.h"
#include "Ragdoll.h"
#include "Tree.h"
#include "Netherite.h"
#include "MyContactListener.h"
#include "Game.h"
#include "Menu.h"

class Level2 : public Scene {
private:

	//World, gravedad y Step
	b2World* world = NULL;
	b2Vec2 gravity;
	float timeStep = 0.1;
	int velocityIterations = 8;
	int positionIterations = 8;

	//posicion del mouse
	Vector2i LP;

	bool isButtonRelessed = false;
	vector <Ragdoll*> rd{};

	//cañon
	Canyon* canyon = nullptr;

	//Arbol
	Tree* t1 = NULL;

	//Netherite
	Netherite* n1 = NULL;

	//Contact Listener
	MyContactListener* MCL = NULL;

	//Camara
	View* view;
	bool isZoom = false;

	Font font;
	Text winLevel, menu, puntaje, restart, esc;
	int int_puntaje;
	bool win = false;
	bool sinvidas = false;
	bool escrelessed = true;
	bool pause = false;

	//Bodys, texturas, sprites y avatares
	b2Body* lum = NULL;
	Avatar* a_lum = NULL;
	Texture* tlum = NULL;
	Sprite* slum = NULL;

	b2Body* blaze = NULL;
	Avatar* a_blaze = NULL;
	Texture* tblaze = NULL;
	Sprite* sblaze = NULL;

	b2Body* brickwall1 = NULL;
	Avatar* a_brickwall1 = NULL;
	Texture* tbrickwall1 = NULL;
	Sprite* sbrickwall1 = NULL;

	b2Body* brickwall11 = NULL;
	Avatar* a_brickwall11 = NULL;
	Texture* tbrickwall11 = NULL;
	Sprite* sbrickwall11 = NULL;

	b2Body* brickwall2 = NULL;
	Avatar* a_brickwall2 = NULL;
	Texture* tbrickwall2 = NULL;
	Sprite* sbrickwall2 = NULL;

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

	Sprite sBackground;
	Texture tBackground;

	Sprite sRetry;
	Texture tRetry;

	Sprite s_UI;
	Texture t_UI;

	//Distance Joint blaze-bloque luminoso
	b2DistanceJointDef jointDef_blaze;
	b2DistanceJoint* distJoint_blaze = NULL;

public:
	Level2();
	void Update(Game& game) override;
	void Draw(RenderWindow& window) override;
};