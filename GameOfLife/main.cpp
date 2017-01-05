#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameOfLife.hh"
#include "GOLGraphics.h"
#include "GOLMapGen.h"

#define	FRAMERATE	60

int		main()
{
	//GameOfLife			gol("./golMap/GosperGliderGun.gol");
	GOLMapGen::GOLMap*	map;
	map = GOLMapGen::Generate(300, 300);
	GameOfLife			gol(map->map, map->x, map->y);
	GOLGraphics			golg(gol.GetWidth(), gol.GetHeight());
	sf::RenderWindow	window(
		sf::VideoMode(CELL_SIZE * gol.GetWidth(), CELL_SIZE * gol.GetHeight()),
		"The Game Of Life !");
	
	if (gol.IsReadyToGo() == false) { return (-1); }
	
	window.setFramerateLimit(FRAMERATE);
	while (window.isOpen())
	{
		gol.Generate();

		window.clear();
		golg.Draw(gol, &window);
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
	}

	return (0);
}
