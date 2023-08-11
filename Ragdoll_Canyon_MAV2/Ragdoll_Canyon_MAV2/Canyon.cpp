#include "canyon.h"

Canyon::Canyon(b2World* world) {
	this->world = world;

	//Se carga la textura y se crea y configura el cuerpo del cañon
	s_canyon = new Sprite;
	t_canyon = new Texture;
	t_canyon->loadFromFile("Assets/Sprites/Canyon.png");
	s_canyon->setTexture(*t_canyon);

	b2BodyDef bdydef_canyon;
	b2PolygonShape ps_canyon;
	b2FixtureDef fix_def_canyon;

	bdydef_canyon.type = b2_kinematicBody;
	bdydef_canyon.position.Set(4, 26);
	bdy_canyon = world->CreateBody(&bdydef_canyon);
	ps_canyon.SetAsBox(1.f, 0.5f);
	fix_def_canyon.density = 0.01f;
	fix_def_canyon.friction = 1.1f;
	fix_def_canyon.restitution = 0.0;
	fix_def_canyon.shape = &ps_canyon;
	bdy_canyon->CreateFixture(&fix_def_canyon);
	a_canyon = new Avatar(bdy_canyon, s_canyon);

}

void Canyon::Update(Vector2i LP) {
	localPosition = LP;
	m_pos = a_canyon->GetSprite()->getPosition();

	//Esto funciona con trigonometria, es un calculo segun el cuadrante en el que se encuentre
	//El punto el origen seria el centro del cañon.
	if (localPosition.x > m_pos.x && m_pos.y > localPosition.y) {
		ca = localPosition.x - m_pos.x;
		co = m_pos.y - localPosition.y;
		float angulo = atan(co / ca) * 57.2958;
		m_angle = angulo;
		C1.x = ca;
		C1.y = co;
	}
	else if (localPosition.x < m_pos.x && m_pos.y > localPosition.y) {
		ca = m_pos.y - localPosition.y;
		co = m_pos.x - localPosition.x;
		float angulo = atan(co / ca) * 57.2958;
		angulo += 90;
		m_angle = angulo;
		C2.x = -co;
		C2.y = ca;
	}
	else if (localPosition.x < m_pos.x && m_pos.y < localPosition.y) {
		ca = m_pos.x - localPosition.x;
		co = localPosition.y - m_pos.y;
		float angulo = atan(co / ca) * 57.2958;
		angulo += 180;
		m_angle = angulo;
		C3.x = -co;
		C3.y = -ca;
	}
	else if (localPosition.x > m_pos.x && m_pos.y < localPosition.y) {
		ca = localPosition.y - m_pos.y;
		co = localPosition.x - m_pos.x;
		float angulo = atan(co / ca) * 57.2958;
		angulo += 270;
		m_angle = angulo;
		C4.x = co;
		C4.y = -ca;
	}

	a_canyon->Actualizar(); //Se actualiza el avatar
	a_canyon->GetSprite()->setRotation(-m_angle); //Se actualiza el angulo
}

void Canyon::Draw(RenderWindow& w) {
	a_canyon->Dibujar(w);
}

Vector2f Canyon::getDistance() {
	//Se obtiene y retorna la distancia
	if(m_angle >= 0 && m_angle <= 90) return C1;
	else if(m_angle >= 90 && m_angle <= 180) return C2;
	else if (m_angle >= 180 && m_angle <= 270) return C3;
	else if (m_angle >= 270 && m_angle <= 360) return C4;
}