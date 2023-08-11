#include "MyContactListener.h"

void MyContactListener::EndContact(b2Contact* contact) {
	//Esta funcion detecta cuando dos cuerpos que estan colisionando entre
	//Si dejan de colisionar. En este caso no hace falta utilizarla
}

void MyContactListener::BeginContact(b2Contact* contact){
	//Cuando un cuerpo entre en contacto con otro se llama a esta funcion
	//donde el objeto contact tendra los dos objetos que colisionan
	//Mediante los user data compararemos y veremos si se trata de la
	//colision de los cuerpos que queremos detectar

	//Obtenemos del User Data
	b2FixtureUserData B2B = contact->GetFixtureB()->GetUserData();
	b2FixtureUserData B2A = contact->GetFixtureA()->GetUserData();

	//Comparamos (Se crea la condicion porque solo necesitamos detectar la colision una sola vez)
	//1 y 2 Son los users data del ragdoll y de la Netherite
	if (!touched) {
		if ((B2A.pointer == 2 && B2B.pointer == 1) || (B2A.pointer == 1 && B2B.pointer == 2)) {
			touched = true;
		}
	}
}