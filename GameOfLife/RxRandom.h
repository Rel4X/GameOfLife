#pragma once

/* Version 1.0 */

#include	<random>
#include	<ctime>

class		RxRandom
{
private:
	static bool		p_initialized;

private:
	RxRandom(void)		{ }
	~RxRandom(void)		{ }

public:
	static void			Init();
	static int			Randomize(unsigned int, unsigned int);
};

