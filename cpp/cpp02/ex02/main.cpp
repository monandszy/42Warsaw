#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  Fixed c(Fixed(5.05f) + Fixed(2));
  std::cout << c << std::endl;
  Fixed d(Fixed(5.05f) - Fixed(2));
  std::cout << d << std::endl;
  Fixed e(Fixed(5.05f) / Fixed(2));
  std::cout << e << std::endl;
  return 0;
}