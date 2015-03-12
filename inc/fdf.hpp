#ifndef _FDF_H_
#define _FDF_H_

#include <SFML/Graphics.hpp>

extern "C"
{
  #include "libNoise.h"
}

class Fdf
{
public:
  Fdf(unsigned int seed);
  ~Fdf() = default;

  void	run();
private:
  sf::RenderWindow	_window;
};

#endif /* _FDF_H_ */
