#include "Tree.h"

Tree::Tree(b2World* world) {

	//Se cargan las texturas y se agregar a los sprites
	tTronco.loadFromFile("Assets/Sprites/Tronco.png");
	sTronco.setTexture(tTronco);

	thojas1.loadFromFile("Assets/Sprites/Hojas1.png");
	shojas1.setTexture(thojas1);
	shojas4.setTexture(thojas1);

	thojas2.loadFromFile("Assets/Sprites/Hojas2.png");
	shojas2.setTexture(thojas2);
	shojas3.setTexture(thojas2);

	thojas3.loadFromFile("Assets/Sprites/Hojas3.png");
	shojas5.setTexture(thojas3);

	//Se configura el tronco (Static)
	bdydef_tronco = new b2BodyDef;
	ps_tronco = new b2PolygonShape;
	fix_def_tronco = new b2FixtureDef;

	bdydef_tronco->type = b2_staticBody;
	bdydef_tronco->position.Set(20, 23);
	bdy_tronco = world->CreateBody(bdydef_tronco);
	ps_tronco->SetAsBox(1.f, 5.f);
	fix_def_tronco->density = 1.00f;
	fix_def_tronco->friction = 0.1;
	fix_def_tronco->restitution = 0.2;
	fix_def_tronco->shape = ps_tronco;
	bdy_tronco->CreateFixture(fix_def_tronco);
	a_tronco = new Avatar(bdy_tronco, &sTronco);


	//Hojas 1
	bdydef_hojas1 = new b2BodyDef;
	ps_hojas1 = new b2PolygonShape;
	fix_def_hojas1 = new b2FixtureDef;

	bdydef_hojas1->type = b2_dynamicBody;
	bdydef_hojas1->position.Set(20, 17);
	bdy_hojas1 = world->CreateBody(bdydef_hojas1);
	ps_hojas1->SetAsBox(5.f, 1.f);
	fix_def_hojas1->density = 1.00f;
	fix_def_hojas1->friction = 0.1;
	fix_def_hojas1->restitution = 0.2;
	fix_def_hojas1->shape = ps_hojas1;
	bdy_hojas1->CreateFixture(fix_def_hojas1);
	a_hojas1 = new Avatar(bdy_hojas1, &shojas1);


	//Hojas 2
	bdydef_hojas2 = new b2BodyDef;
	ps_hojas2 = new b2PolygonShape;
	fix_def_hojas2 = new b2FixtureDef;

	bdydef_hojas2->type = b2_dynamicBody;
	bdydef_hojas2->position.Set(20, 15);
	bdy_hojas2 = world->CreateBody(bdydef_hojas2);
	ps_hojas2->SetAsBox(7.f, 1.f);
	fix_def_hojas2->density = 1.00f;
	fix_def_hojas2->friction = 0.1;
	fix_def_hojas2->restitution = 0.2;
	fix_def_hojas2->shape = ps_hojas2;
	bdy_hojas2->CreateFixture(fix_def_hojas2);
	a_hojas2 = new Avatar(bdy_hojas2, &shojas2);


	//Hojas 3
	bdydef_hojas3 = new b2BodyDef;
	ps_hojas3 = new b2PolygonShape;
	fix_def_hojas3 = new b2FixtureDef;

	bdydef_hojas3->type = b2_dynamicBody;
	bdydef_hojas3->position.Set(20, 13);
	bdy_hojas3 = world->CreateBody(bdydef_hojas3);
	ps_hojas3->SetAsBox(7.f, 1.f);
	fix_def_hojas3->density = 1.00f;
	fix_def_hojas3->friction = 0.1;
	fix_def_hojas3->restitution = 0.3;
	fix_def_hojas3->shape = ps_hojas3;
	bdy_hojas3->CreateFixture(fix_def_hojas3);
	a_hojas3 = new Avatar(bdy_hojas3, &shojas3);


	//Hojas 4
	bdydef_hojas4 = new b2BodyDef;
	ps_hojas4 = new b2PolygonShape;
	fix_def_hojas4 = new b2FixtureDef;

	bdydef_hojas4->type = b2_dynamicBody;
	bdydef_hojas4->position.Set(20, 11);
	bdy_hojas4 = world->CreateBody(bdydef_hojas4);
	ps_hojas4->SetAsBox(5.f, 1.f);
	fix_def_hojas4->density = 1.00f;
	fix_def_hojas4->friction = 0.1;
	fix_def_hojas4->restitution = 0.3;
	fix_def_hojas4->shape = ps_hojas4;
	bdy_hojas4->CreateFixture(fix_def_hojas4);
	a_hojas4 = new Avatar(bdy_hojas4, &shojas4);


	//Hojas 5
	bdydef_hojas5 = new b2BodyDef;
	ps_hojas5 = new b2PolygonShape;
	fix_def_hojas5 = new b2FixtureDef;

	bdydef_hojas5->type = b2_dynamicBody;
	bdydef_hojas5->position.Set(20, 9);
	bdy_hojas5 = world->CreateBody(bdydef_hojas5);
	ps_hojas5->SetAsBox(3.f, 1.f);
	fix_def_hojas5->density = 1.00f;
	fix_def_hojas5->friction = 0.1;
	fix_def_hojas5->restitution = 0.3;
	fix_def_hojas5->shape = ps_hojas5;
	bdy_hojas5->CreateFixture(fix_def_hojas5);
	a_hojas5 = new Avatar(bdy_hojas5, &shojas5);
}

void Tree::Update() {
	a_tronco->Actualizar();
	a_hojas1->Actualizar();
	a_hojas2->Actualizar();
	a_hojas3->Actualizar();
	a_hojas4->Actualizar();
	a_hojas5->Actualizar();
}

void Tree::Draw(RenderWindow& w) {
	a_tronco->Dibujar(w);
	a_hojas1->Dibujar(w);
	a_hojas2->Dibujar(w);
	a_hojas3->Dibujar(w);
	a_hojas4->Dibujar(w);
	a_hojas5->Dibujar(w);
}