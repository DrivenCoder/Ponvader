#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:
	Game();

	void run();

private:
	void handleEvents();
	void playerInput();
	void update();
	void render();

private:
	sf::RenderWindow gameWindow;


};

