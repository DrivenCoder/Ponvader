#include "Game.hpp"

Game::Game() :
	gameWindow(sf::VideoMode(800, 600), "Ponvader")
{
	backgroundTexture.loadFromFile("./assets/textures/starsBackground.png");
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 800, 600));

	playerTexture.loadFromFile("./assets/textures/paddle.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(50, 550);
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
	gameWindow.draw(backgroundSprite);
	gameWindow.draw(playerSprite);
	gameWindow.display();
}