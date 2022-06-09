#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <fstream>
#include <array>

#include "Board.h"

int main()
{
	Board board_1;

	sf::RenderWindow window;
	window.create(sf::VideoMode{ 1024, 610 }, "Boards");
	//window.setFramerateLimit(0);
	sf::Event event;
	sf::Texture boardTexture;
	sf::Texture GridTexture;
	sf::Sprite board;
	sf::Sprite botgrid;
	sf::Sprite usergrid;

	boardTexture.loadFromFile("Plansze.png");
	window.display();
	board.setTexture(boardTexture);
	GridTexture.loadFromFile("net.png");

	usergrid.setTexture(GridTexture);
	botgrid.setTexture(GridTexture);
	usergrid.setPosition(50, 150);
	botgrid.setPosition(650, 150);
	

	
	while (true)
	{


		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}
		
		window.clear();
		window.draw(board);
		window.draw(usergrid);
		window.draw(botgrid);
		board_1.setUserGrid();
		board_1.readUserGridInfo(window);
		board_1.addSensorsToGrid();
		board_1.addBoxToSquare(window);
		board_1.gridEvent( window);
		window.display();
		/*void readUserGridInfo(sf::RenderWindow&);
	void setUserGrid();
	void addSensorsToGrid();
	//void detectBoatOnGrid(Boat&);
	void setBoatOnGrid(int&, const int&);
	bool gridEvent(sf::RenderWindow&);*/
	}
	return 0;
}
