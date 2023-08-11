#include "Level1.h"

Level1::Level1() {

	//Gravedad y creacion del mundo
	gravity.Set(0.0f, 4.0);
	world = new b2World(gravity);

	//cañon
	canyon = new Canyon(world);
	
	//Se crea el contact listener y se lo asigna al mundo
	MCL = new MyContactListener;
	world->SetContactListener(MCL);

	//Se cargan los assets, se asignan (Texturtes a Sprites y Fonts a Text) y se configuran
	tBackground.loadFromFile("Assets/Sprites/Background.jpg");
	sBackground.setTexture(tBackground);
	sBackground.setScale(0.06,0.0725);
	sBackground.setPosition(2, 2);

	tRetry.loadFromFile("Assets/Sprites/RetryIcon.png");
	sRetry.setTexture(tRetry);
	sRetry.setPosition(35,2);
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

	siguiente.setFont(font);
	siguiente.setString("Next Level");
	siguiente.setScale(0.04, 0.04);
	siguiente.setPosition(25.5, 22);

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
	restart.setPosition(17, 22);

	esc.setFont(font);
	esc.setString("esc");
	esc.setScale(0.04, 0.04);
	esc.setPosition(35, 2.5);

	int_puntaje = 6;


	//Se crean los objetos fisicos


	//Se crea el ground
	tground = new Texture;
	sground = new Sprite;
	tground->loadFromFile("Assets/Sprites/Ground.png");
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
	troof->loadFromFile("Assets/Sprites/Ground.png");
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
	tlwall->loadFromFile("Assets/Sprites/Wall.png");
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
	trwall->loadFromFile("Assets/Sprites/Wall.png");
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

	//Se crea el arbol
	t1 = new Tree(world);

	//Se crea la Netherite
	n1 = new Netherite(world);
}

void Level1::Update(Game& game) {

	//Paso del mundo
	world->Step(timeStep, velocityIterations, positionIterations);
	canyon->Update(LP); //Update cañon
	n1->Update(); //Update Netherite

	//Update ragdolls
	for (int i = 0; i < rd.size(); i++) {
		rd[i]->Update();
	}

	t1->Update(); //Update Tree

	if (int_puntaje == 0) {
		sinvidas = true;
	}

	//Boton de Retry
	if ((sRetry.getPosition().x <= LP.x && LP.x <= (sRetry.getPosition().x + sRetry.getGlobalBounds().width)) &&
		(sRetry.getPosition().y <= LP.y && LP.y <= (sRetry.getPosition().y + sRetry.getGlobalBounds().height))) {
		if (Mouse::isButtonPressed(Mouse::Left) && sinvidas) {
			game.SetScene(new Level1);
		}
	}

	//Se cambia a la condicion de victoria cuando se detecto la colision
	if (MCL->touched) {
		win = true;
	}

	//Ventana de victoria
	if (win) {
		if ((siguiente.getPosition().x <= LP.x && LP.x <= (siguiente.getPosition().x + siguiente.getGlobalBounds().width)) &&
			(siguiente.getPosition().y <= LP.y && LP.y <= (siguiente.getPosition().y + siguiente.getGlobalBounds().height))) {
			siguiente.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.SetScene(new Level2);
			}
		}
		else {
			siguiente.setFillColor({ 255,255,255 });
		}

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
				game.SetScene(new Level1);
			}
		}
		else {
			restart.setFillColor({ 255,255,255 });
		}
	}

	//Ventana de pausa
	if (pause) {
		winLevel.setString("Pause");
		winLevel.setPosition(17, 6.5);
		if ((siguiente.getPosition().x <= LP.x && LP.x <= (siguiente.getPosition().x + siguiente.getGlobalBounds().width)) &&
			(siguiente.getPosition().y <= LP.y && LP.y <= (siguiente.getPosition().y + siguiente.getGlobalBounds().height))) {
			siguiente.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.SetScene(new Level2);
			}
		}
		else {
			siguiente.setFillColor({ 255,255,255 });
		}

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
				game.SetScene(new Level1);
			}
		}
		else {
			restart.setFillColor({ 255,255,255 });
		}
	}
	
	//Mientras el jugador no haya ganado nos permite disparar y crear nuevos Ragdolls, restar disparos al hacerlo,
	//Los Ragdolls se disparan segun la distancia del mouse con el cañon. Con escape se abre la ventana de pause
	if (!win) {
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
		if (Keyboard::isKeyPressed(Keyboard::Escape) && escrelessed) {
			if (pause) {
				pause = false;
			}
			else {
				pause = true;
			}
			
			escrelessed = false;
		}
		else if(!Keyboard::isKeyPressed(Keyboard::Escape)){
			escrelessed = true;
		}
	}
	
}

void Level1::Draw(RenderWindow& window) {
	//Se acomoda la el zoom
	if (!isZoom) {
		view = new View(window.getDefaultView());
		view->setSize(40, 30);
		view->setCenter(20, 15);
		window.setView(*view);
		isZoom = true;
	}

	//Se obtiene la poscion del mouse
	LP = Mouse::getPosition(window);
	LP.x /= 20;
	LP.y /= 20;

	window.clear({0,0,0});
	window.draw(sBackground);
	canyon->Draw(window);
	n1->Draw(window);

	a_ground->Dibujar(window);
	a_roof->Dibujar(window);
	a_lwall->Dibujar(window);
	a_rwall->Dibujar(window);
	
	t1->Draw(window);
	for (int i = 0; i < rd.size(); i++) {
		rd[i]->Draw(window);
	}
	if (pause) {
		window.draw(s_UI);
		window.draw(winLevel);
		window.draw(siguiente);
		window.draw(menu);
		window.draw(restart);
	}
	if (win) {
		window.draw(s_UI);
		window.draw(winLevel);
		window.draw(siguiente);
		window.draw(menu);
		window.draw(restart);
	}
	if (sinvidas) {
		//window.draw(esc);
		window.draw(sRetry);
	}
	window.draw(puntaje);
	window.display();
}