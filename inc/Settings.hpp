#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <SFML/Window/Event.hpp>
extern "C"
{
  #include "libNoise.h"
}

class Settings
{
public:
  Settings(unsigned int seed);
  ~Settings() = default;

  void		handleEvent(const sf::Event &event);

  bool		toUpdate();
  float		getScale() const { return _scale; }
  int		getOctave() const { return _octave; }
  float		getLacunarity() const { return _lacunarity; }

private:
  bool		_update;
  float		_scale;
  int		_octave;
  float		_lacunarity;
  unsigned int	_seed;
};

#endif /* _SETTINGS_H_ */
