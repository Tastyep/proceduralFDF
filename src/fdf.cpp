#include <iostream>
#include "fdf.hpp"

Fdf::Fdf(unsigned int seed, unsigned int sx, unsigned int sy) :
  _window(sf::VideoMode(1600, 900), "Procedural Fdf"),
  _sx(sx), _sy(sy),
  _scale(0.5f),
  _lines(sx + sy),
  _set(seed)
{
  _window.setFramerateLimit(20);
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

  while (_window.isOpen())
    {
      _window.clear();
      while (_window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    _window.close();
	  else
	    _set.handleEvent(event);
	}
      if (_set.toUpdate())
	{
	  _generateHeightMap();
	  _updateLines();
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
  sf::Vector2f	freeSpace = _calcDrawSize(size, pad);

  for (unsigned int y = 0; y < _sy; ++y)
    {
      auto	&line = _lines.at(y);
      for (unsigned int x = 0; x < _sx; ++x)
	{
	  auto	&vertex = line[x];
	  float	ypad = y * pad.y;
	  float xpad = x * pad.x;

	  vertex.position.x = _scale * xpad - _scale * ypad + freeSpace.x;
	  vertex.position.y = -_hmap[idx] * (_scale + 0.5f) + half * xpad + half * ypad + freeSpace.y;
	  _lines[_sy + x][y].position = vertex.position;
	  ++idx;
	}
    }
}

void	Fdf::_generateHeightMap()
{
  float		p;
  float		scale = 0.005f;
  unsigned int	octave = 3;

  _hmap.clear();
  for (unsigned int x = 0; x < _sx; ++x)
    for (unsigned int y = 0; y < _sy; ++y)
      {
	p = fbm_2d(octave, 2.0f, 0.5f, scale, x, y);
	_hmap.push_back(p * 200.f);
      }
}

sf::Vector2f	Fdf::_calcDrawSize(const sf::Vector2u &screenSize,
				   const sf::Vector2f &pad) const
{
  sf::FloatRect	pos;
  float		half = _scale / 2.f;

  pos.left = _scale - _scale * (static_cast<int>(_sy) - 1) * pad.y;
  pos.width = _scale * (static_cast<int>(_sx) - 1) * pad.x - _scale;
  pos.top = -_hmap[0] * (_scale + 0.5);
  pos.height = -_hmap[static_cast<int>(_sy * _sx) - 1] * (_scale + 0.5f) +
    half * (static_cast<int>(_sx) - 1) * pad.x +
    half * (static_cast<int>(_sy) - 1) * pad.y;

  return sf::Vector2f(screenSize.x - (pos.width - std::abs(pos.left)),
		      screenSize.y - (pos.height - std::abs(pos.top))) / 2.f;
}
