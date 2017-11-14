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
	void playerInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time deltaTime);
	void render();

private:
	sf::RenderWindow gameWindow;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	bool playerMoveUp, playerMoveDown, playerMoveLeft, playerMoveRight;

	const float playerSpeed;
	const sf::Time timePerFrame;
};