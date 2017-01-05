#include	"RxRandom.h"

/* Version 1.1 */

bool		RxRandom::p_initialized = false;

void		RxRandom::Init()
{
	if (RxRandom::p_initialized == false)
	{
		srand(time(NULL));
		RxRandom::p_initialized = true;
	}
}

int			RxRandom::Randomize(unsigned int min, unsigned int max)
{
	RxRandom::Init();
	if (min > max)
	{
		unsigned int tmp;

		tmp = max;
		max = min;
		min = tmp;
	}
	if (min == 0 && max == 1)
	{ return (((rand() % 2) + 1) - 1); }
	return ((rand() % max) + min);
}
