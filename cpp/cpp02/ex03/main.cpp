#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
  Point w1(Fixed(0), Fixed(0));
  Point w2(Fixed(10), Fixed(0));
  Point w3(Fixed(10), Fixed(15));

  Point target(Fixed(5), Fixed(0.1f));
  Point target(Fixed(5), Fixed(0));

  std::cout << bsp(w1, w2, w3, target) << std::endl;
}