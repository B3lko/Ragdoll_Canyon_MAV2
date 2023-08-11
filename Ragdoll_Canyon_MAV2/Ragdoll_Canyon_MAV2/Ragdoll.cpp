#include "Ragdoll.h"

Ragdoll::Ragdoll(b2World* world, Vector2f APotencia) {
	this->world = world;
	this->Potencia = APotencia;
	CreateParts();
	CreateJoints();
	ApplyForce();
}

void Ragdoll::Update() {
	a_head->Actualizar();
	a_torso->Actualizar();
	a_left_arm->Actualizar();
	a_right_arm->Actualizar();
	a_left_leg->Actualizar();
	a_right_leg->Actualizar();
}

void Ragdoll::ApplyForce() {
	b2Vec2* AAPotencia = new b2Vec2(Potencia.x * 20, Potencia.y * -20);
	bdy_torso->ApplyForceToCenter(*AAPotencia,false);
}

void Ragdoll::Draw(RenderWindow& w) {
	a_head->Dibujar(w);
	a_torso->Dibujar(w);
	a_left_arm->Dibujar(w);
	a_right_arm->Dibujar(w);
	a_left_leg->Dibujar(w);
	a_right_leg->Dibujar(w);
}

void Ragdoll::CreateParts() {
	//Create Head
	s_head = new Sprite;
	t_head = new Texture;
	t_head->loadFromFile("Assets/Sprites/Head.png");
	s_head->setTexture(*t_head);

	bdydef_head.type = b2_dynamicBody;
	bdydef_head.position.Set(x, y - 1.0);
	bdy_head = world->CreateBody(&bdydef_head);
	ps_head.SetAsBox(0.4f, 0.4f);
	fix_def_Head.density = 0.5f;
	fix_def_Head.friction = 0.5f;
	fix_def_Head.restitution = 0.0;
	fix_def_Head.shape = &ps_head;
	fix_def_Head.userData.pointer = 1;
	bdy_head->CreateFixture(&fix_def_Head);
	a_head = new Avatar(bdy_head, s_head);


	//Create Torso
	s_torso = new Sprite;
	t_torso = new Texture;
	t_torso->loadFromFile("Assets/Sprites/Body.png");
	s_torso->setTexture(*t_torso);

	bdydef_torso = new b2BodyDef;
	ps_torso = new b2PolygonShape;
	fix_def_torso = new b2FixtureDef;

	bdydef_torso->type = b2_dynamicBody;
	bdydef_torso->position.Set(x, y);
	bdy_torso = world->CreateBody(bdydef_torso);
	ps_torso->SetAsBox(0.4f, 0.6f);
	fix_def_torso->density = 1.00f;
	fix_def_torso->friction = 0.1;
	fix_def_torso->restitution = 0.2;
	fix_def_torso->shape = ps_torso;
	fix_def_torso->userData.pointer = 1;
	bdy_torso->CreateFixture(fix_def_torso);
	a_torso = new Avatar(bdy_torso, s_torso);


	//Create Left Arm
	t_arm = new Texture;
	t_arm->loadFromFile("Assets/Sprites/arm.png");
	s_left_arm = new Sprite;
	s_left_arm->setTexture(*t_arm);

	b2BodyDef bdydef_left_arm;
	b2PolygonShape ps_left_arm;
	b2FixtureDef fix_def_left_arm;

	bdydef_left_arm.type = b2_dynamicBody;
	bdydef_left_arm.position.Set(x - 0.6, y);
	bdy_left_arm = world->CreateBody(&bdydef_left_arm);
	ps_left_arm.SetAsBox(0.2, 0.6);
	fix_def_left_arm.density = 0.5f;
	fix_def_left_arm.friction = 0.5;
	fix_def_left_arm.restitution = 0;
	fix_def_left_arm.shape = &ps_left_arm;
	fix_def_left_arm.userData.pointer = 1;
	bdy_left_arm->CreateFixture(&fix_def_left_arm);
	a_left_arm = new Avatar(bdy_left_arm, s_left_arm);


	//Create Right Arm
	s_right_arm = new Sprite;
	s_right_arm->setTexture(*t_arm);

	b2BodyDef bdydef_right_arm;
	b2PolygonShape ps_right_arm;
	b2FixtureDef fix_def_right_arm;

	bdydef_right_arm.type = b2_dynamicBody;
	bdydef_right_arm.position.Set(x + 0.6, y);
	bdy_right_arm = world->CreateBody(&bdydef_right_arm);
	ps_right_arm.SetAsBox(0.2, 0.6);
	fix_def_right_arm.density = 0.5f;
	fix_def_right_arm.friction = 0.5f;
	fix_def_right_arm.restitution = 0;
	fix_def_right_arm.shape = &ps_right_arm;
	fix_def_right_arm.userData.pointer = 1;
	bdy_right_arm->CreateFixture(&fix_def_right_arm);
	a_right_arm = new Avatar(bdy_right_arm, s_right_arm);


	//Create Left Leg
	t_leg = new Texture;
	t_leg->loadFromFile("Assets/Sprites/leg.png");
	s_left_leg = new Sprite;
	s_left_leg->setTexture(*t_leg);

	b2BodyDef bdydef_left_leg;
	b2PolygonShape ps_left_leg;
	b2FixtureDef fix_def_left_leg;

	bdydef_left_leg.type = b2_dynamicBody;
	bdydef_left_leg.position.Set(x - 0.2, y + 1.2);
	bdy_left_leg = world->CreateBody(&bdydef_left_leg);
	ps_left_leg.SetAsBox(0.2, 0.6);
	fix_def_left_leg.density = 0.5f;
	fix_def_left_leg.friction = 0.5f;
	fix_def_left_leg.restitution = 0;
	fix_def_left_leg.shape = &ps_left_leg;
	fix_def_left_leg.userData.pointer = 1;
	bdy_left_leg->CreateFixture(&fix_def_left_leg);
	a_left_leg = new Avatar(bdy_left_leg, s_left_leg);


	//Create Right Leg
	s_right_leg = new Sprite;
	s_right_leg->setTexture(*t_leg);

	b2BodyDef bdydef_right_leg;
	b2PolygonShape ps_right_leg;
	b2FixtureDef fix_def_right_leg;

	bdydef_right_leg.type = b2_dynamicBody;
	bdydef_right_leg.position.Set(x + 0.2, y + 1.2);
	bdy_right_leg = world->CreateBody(&bdydef_right_leg);
	ps_right_leg.SetAsBox(0.2, 0.6);
	fix_def_right_leg.density = .50f;
	fix_def_right_leg.friction = 0.01f;
	fix_def_right_leg.restitution = 0.0;
	fix_def_right_leg.shape = &ps_right_leg;
	fix_def_right_leg.userData.pointer = 1;
	bdy_right_leg->CreateFixture(&fix_def_right_leg);
	a_right_leg = new Avatar(bdy_right_leg, s_right_leg);
}

void Ragdoll::CreateJoints() {
	//Iniciamos el DistanceJoint Head - Body
	jointDef_head.Initialize(bdy_head, bdy_torso, b2Vec2(bdy_head->GetPosition().x, bdy_head->GetPosition().y + 0.4f),
		b2Vec2(bdy_torso->GetPosition().x, bdy_torso->GetPosition().y - 0.6f));
	jointDef_head.length = 0.005f;
	jointDef_head.damping = 0.3f;
	jointDef_head.stiffness = 0.9f;
	jointDef_head.collideConnected = true;
	distJoint_head = (b2DistanceJoint*)world->CreateJoint(&jointDef_head);


	//Revolute Joint Brazo Izquiedo
	b2Vec2 larm_anchorA(bdy_left_arm->GetPosition().x + 0.2, bdy_left_arm->GetPosition().y - 0.6);
	revolutejoindef_larm.enableLimit = true;
	revolutejoindef_larm.Initialize(bdy_left_arm, bdy_torso, larm_anchorA);
	revolutejoindef_larm.lowerAngle = -90 * 3.1415 / 180;
	revolutejoindef_larm.upperAngle = 0 * 3.1415 / 180;
	revolutejoindef_larm.collideConnected = true;
	revolutejoin_larm = (b2RevoluteJoint*)world->CreateJoint(&revolutejoindef_larm);


	 //Revolute Joint Brazo Derecho
	b2Vec2 rarm_anchorA(bdy_right_arm->GetPosition().x - 0.2, bdy_right_arm->GetPosition().y - 0.6);
	revolutejoindef_rarm.enableLimit = true;
	revolutejoindef_rarm.Initialize(bdy_right_arm, bdy_torso, rarm_anchorA);
	revolutejoindef_rarm.lowerAngle = 0 * 3.1415 / 180;
	revolutejoindef_rarm.upperAngle = 90 * 3.1415 / 180;
	revolutejoindef_rarm.collideConnected = true;
	revolutejoin_rarm = (b2RevoluteJoint*)world->CreateJoint(&revolutejoindef_rarm);


	//Revolute Joint Pierna Derecha
	b2Vec2 rleg_anchorA(bdy_right_leg->GetPosition().x + 0.2, bdy_right_leg->GetPosition().y - 0.6);
	revolutejoindef_rleg.enableLimit = true;
	revolutejoindef_rleg.Initialize(bdy_right_leg, bdy_torso, rleg_anchorA);
	revolutejoindef_rleg.lowerAngle = 0 * 3.1415 / 180;
	revolutejoindef_rleg.upperAngle = 45 * 3.1415 / 180;
	revolutejoindef_rleg.collideConnected = true;
	revolutejoin_rleg = (b2RevoluteJoint*)world->CreateJoint(&revolutejoindef_rleg);


	//Revolute Joint Pierna Izquierda
	b2Vec2 lleg_anchorA(bdy_left_leg->GetPosition().x - 0.2, bdy_left_leg->GetPosition().y - 0.6);
	revolutejoindef_lleg.enableLimit = true;
	revolutejoindef_lleg.Initialize(bdy_left_leg, bdy_torso, lleg_anchorA);
	revolutejoindef_lleg.lowerAngle = -45 * 3.1415 / 180;
	revolutejoindef_lleg.upperAngle = 45 * 3.1415 / 180;
	revolutejoindef_lleg.collideConnected = true;
	revolutejoin_lleg = (b2RevoluteJoint*)world->CreateJoint(&revolutejoindef_lleg);
}