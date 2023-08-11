#pragma once
#include "box2d/box2d.h"
#include "Box2D/Box2D.h"
#include <iostream>
#include "Netherite.h"
using namespace std;

class MyContactListener : public b2ContactListener{
private:
public:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	bool touched = false;
};