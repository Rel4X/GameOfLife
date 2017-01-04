#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameOfLife.hh"

#define	CELL_SIZE	20

struct SomePixels
{
	sf::Uint8*		px;
	unsigned int	size;
};

void	FillPixelsArray(SomePixels& px, char r, char g, char b)
{
	for (unsigned int i = 0; i < px.size; i += 4)
	{
		px.px[i] = r; // r?
		px.px[i + 1] = g; // g?
		px.px[i + 2] = b; // b?
		px.px[i + 3] = 255; // a?
	}
}

int		main()
{
	GameOfLife			gol("./golMap/GosperGliderGun.gol");
	sf::RenderWindow	window(
		sf::VideoMode(CELL_SIZE * gol.GetWidth(), CELL_SIZE * gol.GetHeight()),
		"The Game Of Life !");
	SomePixels			px_map;
	sf::Texture			tx_map;
	sf::Sprite			sp_map;
	SomePixels			px_cell;
	sf::Texture			tx_cell;
	sf::Texture			tx_dead;
	sf::Texture			tx_birth;
	sf::Sprite			sp_cell;
	sf::Sprite			sp_dead;
	sf::Sprite			sp_birth;

	px_map.size = ((gol.GetWidth() * CELL_SIZE) * (gol.GetHeight() * CELL_SIZE)) * 4;
	px_map.px = new sf::Uint8[px_map.size]();
	FillPixelsArray(px_map, 0, 0, 0);
	tx_map.create(gol.GetWidth() * CELL_SIZE, gol.GetHeight() * CELL_SIZE);
	tx_map.update(px_map.px);
	sp_map.setTexture(tx_map);

	px_cell.size = (CELL_SIZE * CELL_SIZE) * 4;
	px_cell.px = new sf::Uint8[px_cell.size]();
	FillPixelsArray(px_cell, 255, 0, 0);
	tx_cell.create(CELL_SIZE, CELL_SIZE);
	tx_cell.update(px_cell.px);
	sp_cell.setTexture(tx_cell);
	FillPixelsArray(px_cell, 0, 255, 0);
	tx_dead.create(CELL_SIZE, CELL_SIZE);
	tx_dead.update(px_cell.px);
	sp_dead.setTexture(tx_dead);

	
	if (gol.IsReadyToGo() == false) { return (-1); }
	
	window.setFramerateLimit(30);
	while (window.isOpen())
	{
		gol.Generate();

		window.clear();
		window.draw(sp_map);

		for (unsigned int y = 0; y < gol.GetHeight(); ++y)
		{
			for (unsigned int x = 0; x < gol.GetWidth(); ++x)
			{
				if (gol.GetCell(x, y) == CELL)
				{
					sp_cell.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
					window.draw(sp_cell);
				}
			}
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.display();
		
	}

	return 0;
}

//int	main(int ac, char** av)
//{
//	GameOfLife	gol("./golMap/GosperGliderGun.gol");
//  int i = 0;
//  int a;
//  bool		test;
//
//  if (gol.IsReadyToGo() == false) { return (-1); }
//  gol.PrintConsole();
//  while (1)
//    {
//      std::cin >> a;
//      test = gol.Generate();
//      if (test == false) { return (0); }
//      std::cout << std::endl;
//      gol.PrintConsole();
//    }
//  return (0);
//}
