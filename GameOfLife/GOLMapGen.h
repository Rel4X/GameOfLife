#pragma once

#include <string.h>
#include "GameOfLife.hh"
#include "RxRandom.h"

class	GOLMapGen
{
public:
	struct GOLMap
	{
		char*			map;
		unsigned int	x;
		unsigned int	y;
		unsigned int	area;
	};

public:
	GOLMapGen();
	~GOLMapGen();

public:
	static GOLMap*		Generate(unsigned int x, unsigned int y);
};

