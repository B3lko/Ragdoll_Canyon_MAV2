#pragma once
#include "Avatar.h"
#include <iostream>
using namespace sf;
using namespace std;

class Netherite {
private:

	//Texturas y Sprites
	Texture tNetherite;
	Sprite sNetherite;

	//Mundo
	b2World* world = NULL;

	//Avatar
	Avatar* a_Netherite = NULL;

	//Cuerpo, Polygon y Defs
	b2Body* bdy_Netherite = NULL;
	b2BodyDef* bdydef_Netherite = NULL;
	b2PolygonShape* ps_Netherite = NULL;
	b2FixtureDef* fix_def_Netherite = NULL;

public:
	Netherite(b2World* world);
	void Draw(RenderWindow& w);
	void Update();
};