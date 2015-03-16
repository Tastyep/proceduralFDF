#ifndef _FDF_H_
#define _FDF_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "Settings.hpp"

struct	s_color
{
  sf::Color	c;
  int		min;
  int		max;

  s_color(const sf::Color &color,
	  unsigned int mi,
	  unsigned int ma) :
    c(color), min(mi), max(ma)
  {
  }
};

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
  void		_colorisation(auto &vertex, float z);

private:
  sf::RenderWindow	_window;
  unsigned int		_sx;
  unsigned int		_sy;
  float			_scale;
  std::vector<float>	_hmap;
  std::vector<sf::VertexArray>	_lines;
  std::vector<s_color>	_colors;
  Settings		_set;
};

#endif /* _FDF_H_ */
