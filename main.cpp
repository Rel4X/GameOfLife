#include <iostream>
#include "GameOfLife.hh"

int	main(int ac, char** av)
{
  GameOfLife	gol(av[1]);
  int i = 0;
  int a;
  bool		test;

  if (gol.IsReadyToGo() == false) { return (-1); }
  gol.PrintConsole();
  while (1)
    {
      std::cin >> a;
      test = gol.Generate();
      if (test == false) { return (0); }
      std::cout << std::endl;
      gol.PrintConsole();
    }
  return (0);
}
