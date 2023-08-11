#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Avatar.h"
#include <iostream>
using namespace sf;
using namespace std;

class Canyon {
private:
	b2World* world = NULL;

	//Bodys
	b2Body* bdy_canyon = NULL;

	Avatar* a_canyon = NULL;
	Sprite* s_canyon = NULL;
	Texture* t_canyon = NULL;

	float co; //Cateto Opuesto
	float ca; //Cateto Adyacente

	float m_angle = 0.f;
	Vector2i localPosition;
	Vector2f m_pos;

	Vector2f C1, C2, C3, C4;

public:
	Canyon(b2World* world);
	void Update(Vector2i LP);
	void Draw(RenderWindow& w);
	Vector2f getDistance();
};