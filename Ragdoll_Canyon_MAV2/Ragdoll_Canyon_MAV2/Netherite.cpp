#include "Netherite.h"

Netherite::Netherite(b2World* world) {

	//Se carga la textura y se añade al sprite
	tNetherite.loadFromFile("Assets/Sprites/Netherite.png");
	sNetherite.setTexture(tNetherite);

	//Se crea y configura el body
	bdydef_Netherite = new b2BodyDef;
	ps_Netherite = new b2PolygonShape;
	fix_def_Netherite = new b2FixtureDef;

	bdydef_Netherite->type = b2_dynamicBody;
	bdydef_Netherite->position.Set(30, 5);

	bdy_Netherite = world->CreateBody(bdydef_Netherite);
	ps_Netherite->SetAsBox(0.6f, 0.6f);
	fix_def_Netherite->density = 1.00f;
	fix_def_Netherite->friction = 0.1;
	fix_def_Netherite->restitution = 0.256;
	fix_def_Netherite->shape = ps_Netherite;
	fix_def_Netherite->userData.pointer = 2;
	bdy_Netherite->CreateFixture(fix_def_Netherite);
	a_Netherite = new Avatar(bdy_Netherite, &sNetherite);
}

void Netherite::Draw(RenderWindow& w) {
	a_Netherite->Dibujar(w);
}

void Netherite::Update() {
	a_Netherite->Actualizar();
}