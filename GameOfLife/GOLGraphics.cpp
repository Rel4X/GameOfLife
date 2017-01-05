#include "GOLGraphics.h"

GOLGraphics::GOLGraphics(unsigned int x, unsigned int y)
{
	this->p_width = x;
	this->p_height = y;
	this->px_map.size = ((this->p_width * CELL_SIZE) * (this->p_height * CELL_SIZE)) * 4;
	this->px_map.px = new sf::Uint8[this->px_map.size]();
	this->FillPixelsArray(this->px_map, 0, 0, 0);
	this->tx_map.create(this->p_width * CELL_SIZE, this->p_height * CELL_SIZE);
	this->tx_map.update(this->px_map.px);
	this->sp_map.setTexture(this->tx_map);
	this->px_cell.size = (CELL_SIZE * CELL_SIZE) * 4;
	this->px_cell.px = new sf::Uint8[this->px_cell.size]();
	this->FillPixelsArray(this->px_cell, 255, 0, 0);
	this->tx_cell.create(CELL_SIZE, CELL_SIZE);
	this->tx_cell.update(this->px_cell.px);
	this->sp_cell.setTexture(this->tx_cell);
	this->FillPixelsArray(this->px_cell, 0, 255, 0);
	this->tx_dead.create(CELL_SIZE, CELL_SIZE);
	this->tx_dead.update(this->px_cell.px);
	this->sp_dead.setTexture(this->tx_dead);
	this->FillPixelsArray(this->px_cell, 0, 0, 255);
	this->tx_birth.create(CELL_SIZE, CELL_SIZE);
	this->tx_birth.update(this->px_cell.px);
	this->sp_birth.setTexture(this->tx_birth);
}

GOLGraphics::~GOLGraphics()
{
}

void		GOLGraphics::Draw(const GameOfLife& gol, sf::RenderWindow* win)
{
	win->draw(*this->GetPxMap());
	for (unsigned int y = 0; y < gol.GetHeight(); ++y)
	{
		for (unsigned int x = 0; x < gol.GetWidth(); ++x)
		{
			if (gol.GetCell(x, y) == CELL)
			{
				this->GetPxCell()->setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
				win->draw(*this->GetPxCell());
			}
		}
	}
}

void		GOLGraphics::FillPixelsArray(SomePixels& px, char r, char g, char b)
{
	for (unsigned int i = 0; i < px.size; i += 4)
	{
		px.px[i] = r;
		px.px[i + 1] = g;
		px.px[i + 2] = b;
		px.px[i + 3] = 255;
	}
}
