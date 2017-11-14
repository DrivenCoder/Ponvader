#include "Game.hpp"

Game::Game() :
	gameWindow(sf::VideoMode(800, 600), "Ponvader")
{

}

void Game::run()
{
	while (gameWindow.isOpen())
	{
		handleEvents();
		playerInput();
		update();
		render();
	}
}

void Game::handleEvents()
{
	sf::Event event;

	while (gameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			gameWindow.close();
	}
}

void Game::playerInput()
{

}

void Game::update()
{

}

void Game::render()
{
	gameWindow.clear();
	//draw
	gameWindow.display();
}