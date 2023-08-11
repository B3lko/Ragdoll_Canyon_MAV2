#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "Scene.h"

Menu::Menu() {

	//Se cargan, asignan y configuran los distintos assets (Fonts y Texturas) a los  Sprites y Texts
	font.loadFromFile("Assets/Fonts/Minecraft.ttf");

	t_Title.setFont(font);
	t_Title.setString("¡Ragdoll Canyon!");
	t_Title.setScale(2,2);
	t_Title.setPosition(140,100);
	t_Title.setFillColor({ 255,255,255 });

	t_Play.setFont(font);
	t_Play.setString("Play");
	t_Play.setPosition(100,500);
	t_Play.setFillColor({255,255,255});

	t_Exit.setFont(font);
	t_Exit.setString("Exit");
	t_Exit.setPosition(620,500);
	t_Exit.setFillColor({255,255,255});

	t_Back.setFont(font);
	t_Back.setString("Back");
	t_Back.setPosition(100, 500);
	t_Back.setFillColor({ 255,255,255 });

	t_Lvl1.setFont(font);
	t_Lvl1.setString("Level 1");
	t_Lvl1.setPosition(100, 250);
	t_Lvl1.setFillColor({ 255,255,255 });

	t_Lvl2.setFont(font);
	t_Lvl2.setString("Level 2");
	t_Lvl2.setPosition(570, 250);
	t_Lvl2.setFillColor({ 255,255,255 });
	
	t_Select.setFont(font);
	t_Select.setString("Select a level");
	t_Select.setScale(2,2);
	t_Select.setPosition(200, 100);
	t_Select.setFillColor({ 255,255,255 });

	t_by.setFont(font);
	t_by.setString("¡by Federico Eigler!");
	t_by.setFillColor({ 255,255,0 });
	t_by.setScale(0.5, 0.5);
	t_by.setRotation(-25);
	t_by.setPosition(580, 200);
	t_by.setOrigin(t_by.getGlobalBounds().width/2, t_by.getGlobalBounds().height/2);
	
	t_how.setFont(font);
	t_how.setString("How to play?");
	t_how.setScale(1,1);
	t_how.setPosition(300, 500);

	t_exp1.setFont(font);
	t_exp1.setString("El objetivo es colisionar con la netherite:");
	t_exp1.setPosition(20, 10);

	t_exp2.setFont(font);
	t_exp2.setString("El jugador cuenta con 6 disparos de canion");
	t_exp2.setPosition(20, 60);

	t_exp3.setFont(font);
	t_exp3.setString("Controles:");
	t_exp3.setPosition(20, 160);

	t_exp4.setFont(font);
	t_exp4.setString("Click Iquierdo: Disparar");
	t_exp4.setPosition(20, 200);

	t_exp5.setFont(font);
	t_exp5.setString("Mouse: Apuntar y regular potencia");
	t_exp5.setPosition(20, 240);

	t_exp6.setFont(font);
	t_exp6.setString("Esc: Abrir ventana");
	t_exp6.setPosition(20, 280);

	//Se obtienen los GlobalBounds de los Textos
	FR_Play = t_Play.getGlobalBounds();
	FR_Exit = t_Exit.getGlobalBounds();
	FR_Back = t_Back.getGlobalBounds();
	FR_Lvl1 = t_Lvl1.getGlobalBounds();
	FR_Lvl2 = t_Lvl2.getGlobalBounds();
	FR_how = t_how.getGlobalBounds();

	t_Background.loadFromFile("Assets/Sprites/BackgroundMenu.png");
	s_Background.setTexture(t_Background);


	layer = 0;
	//Layer = 0 MainMenu
	//Layer = 1 Select level
	timer = 10;
}

void Menu::Update(Game &game){
	
	//Esto sirve para el texto que cambia su escala en el tiempo
	if (timer == 13) {
		down = true;
	}
	if (timer == 10) {
		down = false;
	}
	if (down) {
		timer -= 0.125;
	}
	else {
		timer += 0.125;
	}
	t_by.setScale(timer/12, timer/12);



	if (layer == 0) {
		if (LP.x >= t_Play.getPosition().x && LP.x <= (t_Play.getPosition().x + FR_Play.width) && LP.y >= t_Play.getPosition().y && LP.y <= t_Play.getPosition().y + FR_Play.height) {
			t_Play.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left) && isButtonRelessed) {
				layer = 1;
				isButtonRelessed = false;
			}
			else if (!Mouse::isButtonPressed(Mouse::Left)) {
				isButtonRelessed = true;
			}
		}
		else {
			t_Play.setFillColor({ 255,255,255 });
		}

		if (LP.x >= t_Exit.getPosition().x && LP.x <= (t_Exit.getPosition().x + FR_Exit.width) && LP.y >= t_Exit.getPosition().y && LP.y <= t_Exit.getPosition().y + FR_Exit.height) {
			t_Exit.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.m_window.close();
			}
		}
		else {
			t_Exit.setFillColor({ 255,255,255 });
		}

		if (LP.x >= t_how.getPosition().x && LP.x <= (t_how.getPosition().x + FR_how.width) && LP.y >= t_how.getPosition().y && LP.y <= t_how.getPosition().y + FR_how.height) {
			t_how.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left) && isButtonRelessed) {
				layer = 2;
				isButtonRelessed = false;
			}
			else if (!Mouse::isButtonPressed(Mouse::Left)) {
				isButtonRelessed = true;
			}
		}
		else {
			t_how.setFillColor({ 255,255,255 });
		}
	}


	else if (layer == 1) {


		if (LP.x >= t_Back.getPosition().x && LP.x <= (t_Back.getPosition().x + FR_Back.width) && LP.y >= t_Back.getPosition().y && LP.y <= t_Back.getPosition().y + FR_Back.height) {
			t_Back.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left) && isButtonRelessed) {
				layer = 0;
				isButtonRelessed = false;
			}
			else if (!Mouse::isButtonPressed(Mouse::Left)) {
				isButtonRelessed = true;
			}
		}
		else {
			t_Back.setFillColor({ 255,255,255 });
		}


		if (LP.x >= t_Lvl1.getPosition().x && LP.x <= (t_Lvl1.getPosition().x + FR_Lvl1.width) && LP.y >= t_Lvl1.getPosition().y && LP.y <= t_Lvl1.getPosition().y + FR_Lvl1.height) {
			t_Lvl1.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.SetScene(new Level1);
			}
		}
		else {
			t_Lvl1.setFillColor({255,255,255});
		}


		if (LP.x >= t_Lvl2.getPosition().x && LP.x <= (t_Lvl2.getPosition().x + FR_Lvl2.width) && LP.y >= t_Lvl2.getPosition().y && LP.y <= t_Lvl2.getPosition().y + FR_Lvl2.height) {
			t_Lvl2.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				game.SetScene(new Level2);
			}
		}
		else {
			t_Lvl2.setFillColor({ 255,255,255 });
		}

	}
	
	else if (layer == 2) {
		if (LP.x >= t_Back.getPosition().x && LP.x <= (t_Back.getPosition().x + FR_Back.width) && LP.y >= t_Back.getPosition().y && LP.y <= t_Back.getPosition().y + FR_Back.height) {
			t_Back.setFillColor({ 255,255,0 });
			if (Mouse::isButtonPressed(Mouse::Left) && isButtonRelessed) {
				layer = 0;
				isButtonRelessed = false;
			}
			else if (!Mouse::isButtonPressed(Mouse::Left)) {
				isButtonRelessed = true;
			}
		}
		else {
			t_Back.setFillColor({ 255,255,255 });
		}
	}

}

void Menu::Draw (RenderWindow &window){

	//Esta funcion sirve para configurar el zoom de la ventana
	//debido a que el menu tiene un zoom determinado y en los niveles existe otro
	if (!isZoom) {
		view = new View(window.getDefaultView());
		window.setView(*view);
		isZoom = true;
	}

	//Se obtiene la posicion del mouse
	LP = Mouse::getPosition(window);
	window.clear({125,125,125}); //Se limpia la pantalla

	//Dependiendo el layer actual se dibuja uno o el otro
	if (layer == 0) {
		window.draw(s_Background);
		window.draw(t_Title);
		window.draw(t_Play);
		window.draw(t_Exit);
		window.draw(t_by);
		window.draw(t_how);
	}
	else if (layer == 1) {
		window.draw(s_Background);
		window.draw(t_Back);
		window.draw(t_Lvl1);
		window.draw(t_Lvl2);
		window.draw(t_Select);
	}
	else if (layer == 2) {
		window.draw(s_Background);
		window.draw(t_Back);
		window.draw(t_exp1);
		window.draw(t_exp2);
		window.draw(t_exp3);
		window.draw(t_exp4);
		window.draw(t_exp5);
		window.draw(t_exp6);
	}
	window.display();
}
