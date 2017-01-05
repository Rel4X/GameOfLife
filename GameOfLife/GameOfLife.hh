#ifndef	__GAMEOFLIFE_HH__
#define	__GAMEOFLIFE_HH__

#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

#define	ERROR	0
#define	EMPTY	' '
#define	CELL	'X'
#define	BIRTH	3
#define ALIVE	2

class	GameOfLife
{
private:
  bool			p_ready_to_go;
  unsigned int	p_width;
  unsigned int	p_height;
  unsigned int	p_area;
  char*			p_earth;
  char*			p_future;

private:
  GameOfLife() { }

public:
  GameOfLife(const char* fname);
  GameOfLife(char* map, unsigned int x, unsigned int y);
  ~GameOfLife();

public:
  bool					IsReadyToGo() const { return (this->p_ready_to_go); }
  const unsigned int	GetWidth() const { return (this->p_width); }
  const unsigned int	GetHeight() const { return (this->p_height); }
  const unsigned int	GetArea() const { return (this->p_area); }
  const char*			GetEarth() const { return (this->p_earth); }

public:
  bool		Generate();
  unsigned int	GetNeighbors(unsigned int x, unsigned int y);
  char		GetCell(unsigned int x, unsigned int y) const;
  void		SetFutureCell(unsigned int x, unsigned int y, char c);
  void		PrintConsole();

private:
  bool		LoadFile(const char* fname);
  bool		CheckChar();

};

#endif	// __GAMEOFLIFE_HH__
