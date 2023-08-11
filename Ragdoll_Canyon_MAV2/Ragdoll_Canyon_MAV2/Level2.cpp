#include "Level2.h"

Level2::Level2() {

	//Se configura la gravedad y crea el mundo
	gravity.Set(0.0f, 4.0);
	world = new b2World(gravity);

	//Se crea el cañon
	canyon = new Canyon(world);

	//Se crea el contact listener y se lo asigna al mundo (Para detectar colisiones)
	MCL = new MyContactListener;
	world->SetContactListener(MCL);

	//Se crea la Netherite
	n1 = new Netherite(world);

	int_puntaje = 6;

	//Se cargan las texturas y se las asigna a los sprites
	tBackground.loadFromFile("Assets/Sprites/Hell.png");
	sBackground.setTexture(tBackground);
	sBackground.setScale(0.0187, 0.0242);
	sBackground.setPosition(2, 2);

	tRetry.loadFromFile("Assets/Sprites/RetryIcon.png");
	sRetry.setTexture(tRetry);
	sRetry.setPosition(35, 2);
	sRetry.scale(0.05, 0.05);

	t_UI.loadFromFile("Assets/Sprites/UI.png");
	s_UI.setTexture(t_UI);
	s_UI.setScale(0.07, 0.07);
	s_UI.setPosition(6.2, 4.7);

	font.loadFromFile("Assets/Fonts/Minecraft.ttf");

	winLevel.setFont(font);
	winLevel.setString("¡Nivel Superado!");
	winLevel.setScale(0.07, 0.07);
	winLevel.setPosition(11.5, 6.5);

	menu.setFont(font);
	menu.setString("Menu");
	menu.setScale(0.04, 0.04);
	menu.setPosition(8.5, 22);

	puntaje.setFont(font);
	puntaje.setString("Remaining Shots: 6");
	puntaje.setScale(0.05, 0.05);
	puntaje.setPosition(2.5, 2.2);

	restart.setFont(font);
	restart.setString("Restart");
	restart.setScale(0.04, 0.04);
	restart.setPosition(25.5, 22);


	//Se crean los objetos de Box2D


	//Se crea el ground
	tground = new Texture;
	sground = new Sprite;
	tground->loadFromFile("Assets/Sprites/Ground-hell.png");
	sground->setTexture(*tground);

	b2BodyDef bdydef_ground;
	b2PolygonShape ps_ground;
	b2FixtureDef fix_def_ground;

	bdydef_ground.type = b2_staticBody;
	bdydef_ground.position.Set(20, 29);
	ground = world->CreateBody(&bdydef_ground);
	ps_ground.SetAsBox(20, 1);
	fix_def_ground.restitution = 0.f;
	fix_def_ground.density = 1.f;
	fix_def_ground.friction = 0.5f;
	fix_def_ground.shape = &ps_ground;
	ground->CreateFixture(&fix_def_ground);
	a_ground = new Avatar(ground, sground);


	//Se crea el roof
	troof = new Texture;
	sroof = new Sprite;
	troof->loadFromFile("Assets/Sprites/Ground-hell.png");
	sroof->setTexture(*troof);

	b2BodyDef bdydef_roof;
	b2PolygonShape ps_roof;
	b2FixtureDef fix_def_roof;

	bdydef_roof.type = b2_staticBody;
	bdydef_roof.position.Set(20, 1);
	roof = world->CreateBody(&bdydef_roof);
	ps_roof.SetAsBox(20, 1);
	fix_def_roof.restitution = 0.f;
	fix_def_roof.density = 1.f;
	fix_def_roof.friction = 0.5f;
	fix_def_roof.shape = &ps_roof;
	roof->CreateFixture(&fix_def_roof);
	a_roof = new Avatar(roof, sroof);


	//Se crea el left wall
	tlwall = new Texture;
	slwall = new Sprite;
	tlwall->loadFromFile("Assets/Sprites/Wall-hell.png");
	slwall->setTexture(*tlwall);

	b2BodyDef bdydef_lwall;
	b2PolygonShape ps_lwall;
	b2FixtureDef fix_def_lwall;

	bdydef_lwall.type = b2_staticBody;
	bdydef_lwall.position.Set(1, 15);
	lwall = world->CreateBody(&bdydef_lwall);
	ps_lwall.SetAsBox(1, 13);
	fix_def_lwall.restitution = 0.f;
	fix_def_lwall.density = 1.f;
	fix_def_lwall.friction = 0.5f;
	fix_def_lwall.shape = &ps_lwall;
	lwall->CreateFixture(&fix_def_lwall);
	a_lwall = new Avatar(lwall, slwall);


	//Se crea el right wall
	trwall = new Texture;
	srwall = new Sprite;
	trwall->loadFromFile("Assets/Sprites/Wall-hell.png");
	srwall->setTexture(*trwall);

	b2BodyDef bdydef_rwall;
	b2PolygonShape ps_rwall;
	b2FixtureDef fix_def_rwall;

	bdydef_rwall.type = b2_staticBody;
	bdydef_rwall.position.Set(39, 15);
	rwall = world->CreateBody(&bdydef_rwall);
	ps_rwall.SetAsBox(1, 13);
	fix_def_rwall.restitution = 0.f;
	fix_def_rwall.density = 1.f;
	fix_def_rwall.friction = 0.5f;
	fix_def_rwall.shape = &ps_lwall;
	rwall->CreateFixture(&fix_def_rwall);
	a_rwall = new Avatar(rwall, srwall);


	//Se crea el bloque de piedra luminosa
	tlum = new Texture;
	slum = new Sprite;
	tlum->loadFromFile("Assets/Sprites/PiedraLuminosa.png");
	slum->setTexture(*tlum);

	b2BodyDef bdydef_lum;
	b2PolygonShape ps_lum;
	b2FixtureDef fix_def_lum;

	bdydef_lum.type = b2_staticBody;
	bdydef_lum.position.Set(20, 3);
	lum = world->CreateBody(&bdydef_lum);
	ps_lum.SetAsBox(1, 1);
	fix_def_lum.restitution = 0.f;
	fix_def_lum.density = 1.f;
	fix_def_lum.friction = 0.5f;
	fix_def_lum.shape = &ps_lum;
	lum->CreateFixture(&fix_def_lum);
	a_lum = new Avatar(lum, slum);


	//Se crea el blaze (Obstaculo con Joints (Pendulo))
	tblaze = new Texture;
	sblaze = new Sprite;
	tblaze->loadFromFile("Assets/Sprites/blaze.png");
	sblaze->setTexture(*tblaze);

	b2BodyDef bdydef_blaze;
	b2PolygonShape ps_blaze;
	b2FixtureDef fix_def_blaze;

	bdydef_blaze.type = b2_dynamicBody;
	bdydef_blaze.position.Set(20, 10);
	blaze = world->CreateBody(&bdydef_blaze);
	ps_blaze.SetAsBox(2, 3);
	fix_def_blaze.restitution = 0.f;
	fix_def_blaze.density = 1.f;
	fix_def_blaze.friction = 0.5f;
	fix_def_blaze.shape = &ps_blaze;
	blaze->CreateFixture(&fix_def_blaze);
	a_blaze = new Avatar(blaze, sblaze);


	//Se crea el Distance Joint del blaze con el bloque luminoso
	jointDef_blaze.Initialize(lum, blaze, b2Vec2(lum->GetPosition().x, lum->GetPosition().y + 1.0f),
		b2Vec2(blaze->GetPosition().x, blaze->GetPosition().y - 2.0f));
	jointDef_blaze.length = 10.5f;
	jointDef_blaze.damping = 0.3f;
	jointDef_blaze.stiffness = 0.9f;
	jointDef_blaze.collideConnected = true;
	distJoint_blaze = (b2DistanceJoint*)world->CreateJoint(&jointDef_blaze);


	//Se crea la pared de ladrillos
	tbrickwall1 = new Texture;
	sbrickwall1 = new Sprite;
	tbrickwall1->loadFromFile("Assets/Sprites/brickwall1.png");
	sbrickwall1->setTexture(*tbrickwall1);

	b2BodyDef bdydef_brickwall1;
	b2PolygonShape ps_brickwall1;
	b2FixtureDef fix_def_brickwall1;

	bdydef_brickwall1.type = b2_dynamicBody;
	bdydef_brickwall1.position.Set(16, 25);
	brickwall1 = world->CreateBody(&bdydef_brickwall1);
	ps_brickwall1.SetAsBox(1, 5);
	fix_def_brickwall1.restitution = 0.f;
	fix_def_brickwall1.density = 1.f;
	fix_def_brickwall1.friction = 0.5f;
	fix_def_brickwall1.shape = &ps_brickwall1;
	brickwall1->CreateFixture(&fix_def_brickwall1);
	a_brickwall1 = new Avatar(brickwall1, sbrickwall1);

	
	//Se crea la pared de ladrillos
	tbrickwall11 = new Texture;
	sbrickwall11 = new Sprite;
	sbrickwall11->setTexture(*tbrickwall1);

	b2BodyDef bdydef_brickwall11;
	b2PolygonShape ps_brickwall11;
	b2FixtureDef fix_def_brickwall11;

	bdydef_brickwall11.type = b2_dynamicBody;
	bdydef_brickwall11.position.Set(24, 25);
	brickwall11 = world->CreateBody(&bdydef_brickwall11);
	ps_brickwall11.SetAsBox(1, 5);
	fix_def_brickwall11.restitution = 0.f;
	fix_def_brickwall11.density = 1.f;
	fix_def_brickwall11.friction = 0.5f;
	fix_def_brickwall11.shape = &ps_brickwall11;
	brickwall11->CreateFixture(&fix_def_brickwall11);
	a_brickwall11 = new Avatar(brickwall11, sbrickwall11);


	//Se crea la pared de ladrillos
	tbrickwall2 = new Texture;
	sbrickwall2 = new Sprite;
	tbrickwall2->loadFromFile("Assets/Sprites/brickwall2.png");
	sbrickwall2->setTexture(*tbrickwall2);

	b2BodyDef bdydef_brickwall2;
	b2PolygonShape ps_brickwall2;
	b2FixtureDef fix_def_brickwall2;

	bdydef_brickwall2.type = b2_dynamicBody;
	bdydef_brickwall2.position.Set(20, 17);
	brickwall2 = world->CreateBody(&bdydef_brickwall2);
	ps_brickwall2.SetAsBox(5, 1);
	fix_def_brickwall2.restitution = 0.f;
	fix_def_brickwall2.density = 1.f;
	fix_def_brickwall2.friction = 0.5f;
	fix_def_brickwall2.shape = &ps_brickwall2;
	brickwall2->CreateFixture(&fix_def_brickwall2);
	a_brickwall2 = new Avatar(brickwall2, sbrickwall2);
}

void Level2::Update(Game& game) {

	//Se asignan los valores para el step del world
	world->Step(timeStep, velocityIterations, positionIterations);
	canyon->Update(LP);//Se actualiza el cañon
	n1->Update(); //Se actualiza la netherite


	//Se actualizan los ragdolls
	for (int i = 0; i < rd.size(); i++) {
		rd[i]->Update();
	}


	//Se actualizan los objetos fisicos
	a_lum->Actualizar();
	a_blaze->Actualizar();
	a_brickwall1->Actualizar();
	a_brickwall11->Actualizar();
	a_brickwall2->Actualizar();


	//Si nos quedamos sin disparos
	if (int_puntaje == 0) {
		sinvidas = true;
	}

	//Si el Ragdoll colisiona con la Netherite
	if (MCL->touched) {
		win = true;
	}


	//Boton de Retry
	if ((sRetry.getPosition().x <= LP.x && LP.x <= (sRetry.getPosition().x + sRetry.getGlobalBounds().width)) &&
		(sRetry.getPosition().y <= LP.y && LP.y <= (sRetry.getPosition().y + sRetry.getGlobalBounds().height))) {
		if (Mouse::isButtonPressed(Mouse::Left) && sinvidas) {
			game.SetScene(new Level2);
		}
	}


	//Si el jugador gano se le muestra la ventana de victoria
	if (win) {

		if ((menu.getPosition().x <= LP.x && LP.x <= (menu.getPosition().x + menu.getGlobalBounds().width)) &&
			(menu.getPosition().y <= LP.y && LP.y <= (menu.getPosition().y + menu.getGlobalBounds().height))) {
			menu.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.SetScene(new Menu);
			}
		}
		else {
			menu.setFillColor({ 255,255,255 });
		}

		if ((restart.getPosition().x <= LP.x && LP.x <= (restart.getPosition().x + restart.getGlobalBounds().width)) &&
			(restart.getPosition().y <= LP.y && LP.y <= (restart.getPosition().y + restart.getGlobalBounds().height))) {
			restart.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.SetScene(new Level2);
			}
		}
		else {
			restart.setFillColor({ 255,255,255 });
		}
	}


	//Se muestra la ventana de pausa
	if (pause) {
		winLevel.setString("Pause");
		winLevel.setPosition(17, 6.5);

		if ((menu.getPosition().x <= LP.x && LP.x <= (menu.getPosition().x + menu.getGlobalBounds().width)) &&
			(menu.getPosition().y <= LP.y && LP.y <= (menu.getPosition().y + menu.getGlobalBounds().height))) {
			menu.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.SetScene(new Menu);
			}
		}
		else {
			menu.setFillColor({ 255,255,255 });
		}

		if ((restart.getPosition().x <= LP.x && LP.x <= (restart.getPosition().x + restart.getGlobalBounds().width)) &&
			(restart.getPosition().y <= LP.y && LP.y <= (restart.getPosition().y + restart.getGlobalBounds().height))) {
			restart.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.SetScene(new Level2);
			}
		}
		else {
			restart.setFillColor({ 255,255,255 });
		}
	}


	//Mientras el jugador no haya ganado nos permite disparar y crear nuevos Ragdolls, restar disparos al hacerlo,
	//Los Ragdolls se disparan segun la distancia del mouse con el cañon. Con escape se abre la ventana de pause
	if (!win) {

		//Crear y disparar ragdolls
		if (Mouse::isButtonPressed(Mouse::Left) && isButtonRelessed && !sinvidas && !pause) {
			int_puntaje--;
			puntaje.setString("Remaining Shots: " + to_string(int_puntaje));
			isButtonRelessed = false;
			Vector2f Distance = canyon->getDistance();
			for (int i = 0; i < rd.size(); i++) {
				rd[i]->Update();
			}
			rd.resize(rd.size() + 1);
			rd[rd.size() - 1] = new Ragdoll(world, Vector2f(Distance.x, Distance.y));
		}
		else if (!Mouse::isButtonPressed(Mouse::Left)) {
			isButtonRelessed = true;
		}

		//Ventana de pausa
		if (Keyboard::isKeyPressed(Keyboard::Escape) && escrelessed) {
			if (pause) {
				pause = false;
			}
			else {
				pause = true;
			}

			escrelessed = false;
		}
		else if (!Keyboard::isKeyPressed(Keyboard::Escape)) {
			escrelessed = true;
		}
	}
}

void Level2::Draw(RenderWindow& window) {

	//Se acomoda el zoom y la camara al nivel actual
	if (!isZoom) {
		view = new View(window.getDefaultView());
		view->setSize(40, 30);
		view->setCenter(20, 15);
		window.setView(*view);
		isZoom = true;
	}

	//Se obtiene la posicion del mouse y se la acomoda con respecto al tamaño de la ventana
	LP = Mouse::getPosition(window);
	LP.x /= 20;
	LP.y /= 20;

	window.clear({ 0,0,0 });

	//Se dibujan los objetos del nivel
	window.draw(sBackground);
	canyon->Draw(window);
	n1->Draw(window);
	a_ground->Dibujar(window);
	a_roof->Dibujar(window);
	a_lwall->Dibujar(window);
	a_rwall->Dibujar(window);
	a_lum->Dibujar(window);
	a_blaze->Dibujar(window);
	a_brickwall1->Dibujar(window);
	a_brickwall11->Dibujar(window);
	a_brickwall2->Dibujar(window);


	//Se dibujan los ragdolls
	for (int i = 0; i < rd.size(); i++) {
		rd[i]->Draw(window);
	}

	//Se dibuja la ventana de victoria
	if (win) {
		window.draw(s_UI);
		window.draw(winLevel);
		window.draw(menu);
		window.draw(restart);
	}

	//Se dibuja la ventana de pausa
	if (pause) {
		window.draw(s_UI);
		window.draw(winLevel);
		window.draw(menu);
		window.draw(restart);
	}

	//Se dibuja el boton de Retry
	if (sinvidas) {
		window.draw(sRetry);
	}

	window.draw(puntaje);
	window.display();
}