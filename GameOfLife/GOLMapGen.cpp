#include "GOLMapGen.h"

GOLMapGen::GOLMapGen()
{
}

GOLMapGen::~GOLMapGen()
{
}

GOLMapGen::GOLMap*		GOLMapGen::Generate(unsigned int x, unsigned int y)
{
	GOLMapGen::GOLMap*	map;
	int					t;

	map = new GOLMapGen::GOLMap();
	map->x = x;
	map->y = y;
	map->area = x * y;
	map->map = new char[map->area]();
	memset(map->map, EMPTY, map->area);
	for (int i = 0; i < map->area; ++i)
	{
		t = RxRandom::Randomize(0, 1);
		if (t == 1) { map->map[i] = CELL; }
	}
	return (map);
}