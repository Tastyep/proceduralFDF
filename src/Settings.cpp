#include <cstdlib>
#include <iostream>
#include "Settings.hpp"

Settings::Settings(unsigned int seed):
  _update(true),
  _scale(0.005f),
  _octave(2),
  _lacunarity(2.f),
  _seed(seed)
{
  std::srand(seed);
  setSeed(seed);
  initPerm();
}

void	Settings::handleEvent(const sf::Event &event)
{
  switch (event.type)
    {
    case sf::Event::KeyPressed:
      {
	switch (event.key.code)
	  {
	  case sf::Keyboard::Return:
	    {
	      unsigned int seed = std::rand();
	      _update = true;
	      std::srand(seed);
	      setSeed(seed);
	      initPerm();
	    }
	  }
      }
      break;
    default:
      break;
    }
}

bool	Settings::toUpdate()
{
  bool	val = _update;

  if (val == true)
    _update = false;
  return val;
}
