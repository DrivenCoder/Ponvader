#include "Game.hpp"

Game::Game() :
	gameWindow(sf::VideoMode(800, 600), "Ponvader"),
	playerMoveUp(false),
	playerMoveDown(false),
	playerMoveLeft(false),
	playerMoveRight(false)
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
		update();
		render();
	}
}

void Game::handleEvents()
{
	sf::Event event;

	while (gameWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case::sf::Event::KeyPressed:
			playerInput(event.key.code, true);
			break;

		case::sf::Event::KeyReleased:
			playerInput(event.key.code, false);
			break;

		case::sf::Event::Closed:
			gameWindow.close();
			break;

		default:
			break;
		}
	}
}

void Game::playerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		playerMoveUp = isPressed;
	else if (key == sf::Keyboard::S)
		playerMoveDown = isPressed;
	else if (key == sf::Keyboard::A)
		playerMoveLeft = isPressed;
	else if (key == sf::Keyboard::D)
		playerMoveRight = isPressed;
}

void Game::update()
{
	if (playerMoveUp)
		std::cout << "Move Up" << std::endl;
	if (playerMoveDown)
		std::cout << "Move Down" << std::endl;
	if (playerMoveLeft)
		std::cout << "Move Left" << std::endl;
	if (playerMoveRight)
		std::cout << "Move Right" << std::endl;
}

void Game::render()
{
	gameWindow.clear();
	gameWindow.draw(backgroundSprite);
	gameWindow.draw(playerSprite);
	gameWindow.display();
}