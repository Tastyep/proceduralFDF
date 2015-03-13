#include <iostream>
#include "fdf.hpp"

Fdf::Fdf(unsigned int seed, unsigned int sx, unsigned int sy) :
  _window(sf::VideoMode(1600, 900), "Procedural Fdf"),
  _sx(sx), _sy(sy),
  _scale(0.5f),
  _lines(sx + sy)
{
  setSeed(seed);
  initPerm();
  _window.setFramerateLimit(15);
  for (auto &line : _lines)
    line.setPrimitiveType(sf::LinesStrip);
  for (unsigned int y = 0; y < sy; ++y)
    _lines[y].resize(sx);
  for (unsigned int x = 0; x < sx; ++x)
    _lines[sy + x].resize(sy);
}

Fdf::~Fdf()
{

}

void	Fdf::run()
{
  sf::Event	event;
  bool		change = true;

  _generateHeightMap();
  while (_window.isOpen())
    {
      _window.clear();
      while (_window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    _window.close();
	}
      if (change)
	{
	  _updateLines();
	  change = false;
	}
      for (auto &line : _lines)
	_window.draw(line);
      _window.display();
    }
}

void	Fdf::_updateLines()
{
  unsigned int	idx = 0;
  sf::Vector2u	size = _window.getSize();
  sf::Vector2f	pad(size.x / _sx, size.y / _sy);
  float		half = _scale / 2.f;

  for (unsigned int y = 0; y < _sy; ++y)
    {
      auto	&line = _lines.at(y);
      for (unsigned int x = 0; x < _sx; ++x)
	{
	  auto	&vertex = line[x];
	  float	ypad = y * pad.y;
	  float xpad = x * pad.x;

	  vertex.position.x = _scale * xpad - _scale * ypad + size.x / 2.75f;
	  vertex.position.y = -_hmap[idx] * (_scale + 0.5f) + half * xpad + half * ypad + size.y / 5.f;
	  _lines[_sy + x][y].position = vertex.position;
	  ++idx;
	}
    }
}

void	Fdf::_generateHeightMap()
{
  float		p;
  float		scale = 0.006f;
  unsigned int	octave = 2;

  for (unsigned int x = 0; x < _sx; ++x)
    for (unsigned int y = 0; y < _sy; ++y)
      {
	p = fbm_2d(octave, 2.f, 0.5f, scale, x, y);
	_hmap.push_back(p * 200.f);
      }
}
