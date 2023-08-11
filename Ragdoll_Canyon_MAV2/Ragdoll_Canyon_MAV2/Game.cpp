#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Scene.h"
#include "Menu.h"
using namespace sf;
using namespace std;
Game::Game() : m_window(VideoMode(800,600),"Eigler_Canyon_Ragdoll"){
	m_window.setFramerateLimit(60);
	view = new View(m_window.getDefaultView());
	m_window.setView(*view);
	m_Scene = new Menu();
}

void Game::Run(){
	while(m_window.isOpen()) {
		ProcessEvents();
		Update();
		Draw();
		if(m_Next_Scene){
			delete m_Scene;
			m_Scene = m_Next_Scene;
			m_Next_Scene = nullptr;
		}
	}
}

void Game::Update(){
	m_Scene->Update(*this);
}

void Game::Draw(){
	m_Scene->Draw(m_window);
}
void Game::ProcessEvents(){
	Event e;
	while(m_window.pollEvent(e)) {
		if(e.type == Event::Closed){
			m_window.close();	}
		
	}
}
void Game::SetScene(Scene * next_Scene){
	m_Next_Scene = next_Scene;
}