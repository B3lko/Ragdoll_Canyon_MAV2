#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
using namespace sf;
class Game{
private:
	RenderWindow m_window;
	friend class Menu;
	Scene *m_Scene;
	Scene *m_Next_Scene = nullptr;
	View* view = NULL;
public:
	Game();
	void Run();
	void Update();
	void Draw();
	void ProcessEvents();
	void SetScene(Scene *next_Scene);
};

#endif
