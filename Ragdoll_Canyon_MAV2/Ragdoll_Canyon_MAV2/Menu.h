#ifndef MENU_H
#define MENU_H
#include "Scene.h"
#include "Game.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Level1.h"
#include "Level2.h"
using namespace std;
#include <iostream>

class Menu : public Scene{
private:
	Font font;
	Text t_Title, t_Play, t_Exit, t_Lvl1, t_Lvl2, t_Back, t_Select, t_by, t_how, t_exp1, t_exp2, t_exp3, t_exp4, t_exp5, t_exp6;
	FloatRect FR_Play, FR_Exit, FR_Back, FR_Lvl1, FR_Lvl2, FR_how;
	Vector2i LP;
	Sprite s_Background;
	Texture t_Background;
	int layer;

	View* view;
	bool isZoom = false;

	float timer = 0;
	bool down = true;

	bool isButtonRelessed = false;

public:
	Menu();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
};

#endif

