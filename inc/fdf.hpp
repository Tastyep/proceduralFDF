#ifndef _FDF_H_
#define _FDF_H_

#include <SFML/Graphics.hpp>
#include <vector>

extern "C"
{
  #include "libNoise.h"
}

class Fdf
{
public:
  Fdf(unsigned int seed,
      unsigned int sx = 300,
      unsigned int sy = 300);
  ~Fdf();

  void	run();

private:
  void		_generateHeightMap();
  void		_updateLines();
  sf::Vector2f	_calcDrawSize(const sf::Vector2u &screenSize,
			      const sf::Vector2f &pad) const;

private:
  sf::RenderWindow	_window;
  unsigned int		_sx;
  unsigned int		_sy;
  float			_scale;
  std::vector<float>	_hmap;
  std::vector<sf::VertexArray>	_lines;
};

#endif /* _FDF_H_ */
