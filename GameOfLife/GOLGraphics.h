#pragma once

#include	<SFML/Graphics.hpp>
#include	"GameOfLife.hh"

#define		CELL_SIZE	5

class GOLGraphics
{
private:
	struct SomePixels
	{
		sf::Uint8*		px;
		unsigned int	size;
	};

private:
	unsigned int		p_width;
	unsigned int		p_height;
	SomePixels			px_map;
	SomePixels			px_cell;
	sf::Texture			tx_map;
	sf::Texture			tx_cell;
	sf::Texture			tx_dead;
	sf::Texture			tx_birth;
	sf::Sprite			sp_map;
	sf::Sprite			sp_cell;
	sf::Sprite			sp_dead;
	sf::Sprite			sp_birth;

private:
	GOLGraphics() { };

public:
	GOLGraphics(unsigned int x, unsigned int y);
	~GOLGraphics();

public:
	sf::Sprite*				GetPxMap() { return (&this->sp_map); }
	sf::Sprite*				GetPxCell() { return (&this->sp_cell); }
	sf::Sprite*				GetPxDead() { return (&this->sp_dead); }
	sf::Sprite*				GetPxBirth() { return (&this->sp_birth); }

public:
	void					Draw(const GameOfLife& gol, sf::RenderWindow* win);

private:
	void		FillPixelsArray(SomePixels& px, char r, char g, char b);
};
