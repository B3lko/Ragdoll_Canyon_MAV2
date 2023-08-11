#pragma once
#include "Avatar.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Ragdoll {
private:

	//Texturas y Sprites
	Sprite* s_head = NULL;
	Texture* t_head = NULL;
	Sprite* s_torso = NULL;
	Texture* t_torso = NULL;
	Sprite* s_left_arm = NULL;
	Texture* t_arm = NULL;
	Sprite* s_right_arm = NULL;
	Sprite* s_left_leg = NULL;
	Texture* t_leg = NULL;
	Sprite* s_right_leg = NULL;

	//Potencia para el disparo
	Vector2f Potencia;

	//Referencia al mundo
	b2World* world = NULL;

	//Se crean los bodys
	b2Body* bdy_head = NULL;
	b2Body* bdy_torso = NULL;
	b2Body* bdy_left_arm = NULL;
	b2Body* bdy_right_arm = NULL;
	b2Body* bdy_left_leg = NULL;
	b2Body* bdy_right_leg = NULL;
	
	//Head
	b2BodyDef bdydef_head;
	b2PolygonShape ps_head;
	b2FixtureDef fix_def_Head;

	//Body
	b2BodyDef* bdydef_torso = NULL;
	b2PolygonShape* ps_torso = NULL;
	b2FixtureDef* fix_def_torso = NULL;

	//Se crean los avatares
	Avatar* a_head = NULL;
	Avatar* a_torso = NULL;
	Avatar* a_left_arm = NULL;
	Avatar* a_right_arm = NULL;
	Avatar* a_left_leg = NULL;
	Avatar* a_right_leg = NULL;

	//Se crean los Joints del Ragdoll
	b2DistanceJointDef jointDef_head;
	b2DistanceJoint* distJoint_head = NULL;

	b2RevoluteJointDef revolutejoindef_larm;
	b2RevoluteJoint* revolutejoin_larm = NULL;

	b2RevoluteJointDef revolutejoindef_rarm;
	b2RevoluteJoint* revolutejoin_rarm = NULL;

	b2RevoluteJointDef revolutejoindef_rleg;
	b2RevoluteJoint* revolutejoin_rleg = NULL;

	b2RevoluteJointDef revolutejoindef_lleg;
	b2RevoluteJoint* revolutejoin_lleg = NULL;

	int x = 5, y =25;

public:
	Ragdoll(b2World* world, Vector2f APotencia);
	void CreateParts();
	void CreateJoints();
	void Update();
	void Draw(RenderWindow& w);
	void ApplyForce();
};