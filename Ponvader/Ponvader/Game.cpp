#include "Game.hpp"

Game::Game() :
	gameWindow(sf::VideoMode(800, 600), "Ponvader"),
	playerMoveUp(false),
	playerMoveDown(false),
	playerMoveLeft(false),
	playerMoveRight(false),
	playerSpeed(500.f),
	timePerFrame(sf::seconds(1.f / 60.f))
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
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (gameWindow.isOpen())
	{
		handleEvents();
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			handleEvents();
			update(timePerFrame);
		} // timePerFrame
		
		render();
	} // isOpen
} // run

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

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);

	if (playerMoveUp)
		movement.y -= playerSpeed;
	if (playerMoveDown)
		movement.y += playerSpeed;
	if (playerMoveLeft)
		movement.x -= playerSpeed;
	if (playerMoveRight)
		movement.x += playerSpeed;

	playerSprite.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	gameWindow.clear();
	gameWindow.draw(backgroundSprite);
	gameWindow.draw(playerSprite);
	gameWindow.display();
}