#include <SFML/Graphics.hpp>

void main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(640, 480), "Ponvader");

	while (gameWindow.isOpen())
	{
		sf::Event event;

		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}

		gameWindow.clear();
		gameWindow.display();
		testing.poop();
	}
}