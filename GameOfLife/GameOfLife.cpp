#include "GameOfLife.hh"

GameOfLife::GameOfLife(const char* fname) :
  p_ready_to_go(false), p_earth(0x0), p_future(0x0)
{
  if (!this->LoadFile(fname))
    {
      std::cout << "BadFile." << std::endl;
      return ;
    }
  this->p_ready_to_go = true;
}

GameOfLife::~GameOfLife()
{
  if (this->p_earth != 0x0)
    delete (this->p_earth);
  if (this->p_future != 0x0)
    delete (this->p_future);
}

bool		GameOfLife::Generate()
{
  if (this->p_earth == 0x0) { return (false); }

  unsigned int	x;
  unsigned int	y;
  unsigned int	nb;

  memset(this->p_future, EMPTY, this->p_area);
  for (y = 0; y < this->p_height; ++y)
    {
      for (x = 0; x < this->p_width; ++x)
	{
	  nb = GetNeighbors(x, y);
	  if (nb == BIRTH)
	    {
	      this->SetFutureCell(x, y, CELL);
	    }
	  else if (this->GetCell(x, y) == CELL && nb == ALIVE)
	    {
	      this->SetFutureCell(x, y, CELL);
	    }
	  else
	    this->SetFutureCell(x, y, EMPTY);
	}
    }
  memcpy(this->p_earth, this->p_future, this->p_area);
  
  return (true);
}

unsigned int	GameOfLife::GetNeighbors(unsigned int x, unsigned int y)
{
  if (this->p_earth == 0x0) { return (-1); }

  unsigned int	nb;

  nb = 0;
  if (this->GetCell(x - 1, y) == CELL) { ++nb; }
  if (this->GetCell(x - 1, y - 1) == CELL) { ++nb; }
  if (this->GetCell(x - 1, y + 1) == CELL) { ++nb; }
  if (this->GetCell(x, y + 1) == CELL) { ++nb; }
  if (this->GetCell(x, y - 1) == CELL) { ++nb; }
  if (this->GetCell(x + 1, y - 1) == CELL) { ++nb; }
  if (this->GetCell(x + 1, y) == CELL) { ++nb; }
  if (this->GetCell(x + 1, y + 1) == CELL) { ++nb; }

  return (nb);
}

char		GameOfLife::GetCell(unsigned int x, unsigned int y)
{
  if (this->p_earth == 0x0) { return (ERROR); }
  if (this->p_ready_to_go == false) { return (ERROR); }
  if (x < this->p_width && y < this->p_height)
    { return (this->p_earth[(this->p_width * y) + x]); }
  return (ERROR);
}

void		GameOfLife::SetFutureCell(unsigned int x, unsigned int y, char c)
 {
   if (this->p_earth == 0x0) { return ; }
   if (this->p_ready_to_go == false) { return ; }
   if (x < this->p_width && y < this->p_height)
     { this->p_future[(this->p_width * y) + x] = c; }
 }

void		GameOfLife::PrintConsole()
{
  if (this->p_earth == 0x0) { return ; }

  int x;
  int y;
  
  for (y = 0; y < this->GetHeight(); ++y)
    {
      for (x = 0; x < this->GetWidth(); ++x)
	{ std::cout << this->GetCell(x, y); }
      std::cout << std::endl;
    }
}

bool		GameOfLife::LoadFile(const char* fname)
{
  struct stat	sb;
  std::ifstream	file(fname, std::ios::in);
  std::string	line;
  int		idx;
  bool		fline;

  if (!file) { return (false); }

  if (stat(fname, &sb)) { file.close(); return (false); }
  this->p_earth = new char[sb.st_size]();
  this->p_future = new char[sb.st_size]();
  memset(this->p_earth, 0, sb.st_size);
  this->p_height = 0;
  idx = 0;
  fline = true;
  while (std::getline(file, line))
    {
      if (fline == true)
	{
	  this->p_width = line.size();
	  fline = false;
	}
      else
	{
	  if (line.size() != this->p_width)
	    {
	      std::cout << "BadLine" << std::endl;
	      delete (this->p_earth);
	      delete (this->p_future);
	      this->p_earth = 0x0;
	      this->p_future = 0x0;
	      file.close();
	      return (false);
	    }
	}
      memcpy(this->p_earth + idx, line.c_str(), line.size());
      idx += line.size();
      ++this->p_height;
    }
  file.close();
  this->p_area = this->p_width * this->p_height;
  return (this->CheckChar());
}

bool		GameOfLife::CheckChar()
{
  if (this->p_earth == 0x0) { return (false); }
  int		i;

  for (i = 0; i < this->p_area; ++i)
    {
      if (this->p_earth[i] != EMPTY && this->p_earth[i] != CELL)
	{
	  std::cout << "BadChar" << std::endl;
	  delete (this->p_earth);
	  delete (this->p_future);
	  this->p_earth == 0x0;
	  this->p_future == 0x0;
	  return (false);
	}
    }
  return (true);
}
