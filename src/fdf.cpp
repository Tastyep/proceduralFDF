#include "fdf.hpp"

Fdf::Fdf(unsigned int seed) :
  _window(sf::VideoMode(1600, 900), "Procedural Fdf")
{
  setSeed(seed);
  initPerm();
  _window.setFramerateLimit(15);
}

void	Fdf::run()
{
  sf::Event	event;

  while (_window.isOpen())
    {
      _window.clear();
      while (_window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    _window.close();
	}
      _window.display();
    }
}
