#include <iostream>
#include "fdf.hpp"

int	main(int argc, char *argv[])
{
  Fdf	fdf(0);

  std::cout << raw_noise_2d(2, 1) << std::endl;
  fdf.run();
  return 0;
}
