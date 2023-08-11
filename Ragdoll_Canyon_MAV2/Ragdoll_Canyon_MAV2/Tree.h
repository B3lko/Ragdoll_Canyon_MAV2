#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Avatar.h"
using namespace sf;

class Tree {
private:
	Texture tTronco, thojas1, thojas2, thojas3;
	Sprite sTronco, shojas1, shojas2, shojas3, shojas4, shojas5;

	b2World* world = NULL;

	Avatar* a_tronco = NULL;

	b2Body* bdy_tronco = NULL;
	b2BodyDef* bdydef_tronco = NULL;
	b2PolygonShape* ps_tronco = NULL;
	b2FixtureDef* fix_def_tronco = NULL;

	Avatar* a_hojas1 = NULL;

	b2Body* bdy_hojas1 = NULL;
	b2BodyDef* bdydef_hojas1 = NULL;
	b2PolygonShape* ps_hojas1 = NULL;
	b2FixtureDef* fix_def_hojas1 = NULL;

	Avatar* a_hojas2 = NULL;

	b2Body* bdy_hojas2 = NULL;
	b2BodyDef* bdydef_hojas2 = NULL;
	b2PolygonShape* ps_hojas2 = NULL;
	b2FixtureDef* fix_def_hojas2 = NULL;

	Avatar* a_hojas3 = NULL;

	b2Body* bdy_hojas3 = NULL;
	b2BodyDef* bdydef_hojas3 = NULL;
	b2PolygonShape* ps_hojas3 = NULL;
	b2FixtureDef* fix_def_hojas3 = NULL;

	Avatar* a_hojas4 = NULL;

	b2Body* bdy_hojas4 = NULL;
	b2BodyDef* bdydef_hojas4 = NULL;
	b2PolygonShape* ps_hojas4 = NULL;
	b2FixtureDef* fix_def_hojas4 = NULL;

	Avatar* a_hojas5 = NULL;

	b2Body* bdy_hojas5 = NULL;
	b2BodyDef* bdydef_hojas5 = NULL;
	b2PolygonShape* ps_hojas5 = NULL;
	b2FixtureDef* fix_def_hojas5 = NULL;


public:
	Tree(b2World* world);
	void Draw(RenderWindow& w);
	void Update();
};