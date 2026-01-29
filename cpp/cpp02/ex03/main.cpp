#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"


int main(void) {
  Point a(0.0f, 0.0f);
  Point b(10.0f, 0.0f);
  Point c(0.0f, 10.0f);

  // Triangle: (0,0) - (10,0) - (0,10)
  std::cout << "Inside" << std::endl;
  std::cout << bsp(a, b, c, Point(1.0f, 1.0f)) << std::endl; // true
  std::cout << bsp(a, b, c, Point(2.0f, 2.0f)) << std::endl; // true

  std::cout << "Outside" << std::endl;
  std::cout << bsp(a, b, c, Point(10.0f, 10.0f)) << std::endl; // false
  std::cout << bsp(a, b, c, Point(-1.0f, -1.0f)) << std::endl; // false
  std::cout << bsp(a, b, c, Point(-1.0f, 1.0f)) << std::endl; // false
  std::cout << bsp(a, b, c, Point(1.0f, -1.0f)) << std::endl; // false

  std::cout << "Vertices" << std::endl;
  std::cout << bsp(a, b, c, Point(0.0f, 0.0f)) << std::endl; // false
  std::cout << bsp(a, b, c, Point(10.0f, 0.0f)) << std::endl; // false
  std::cout << bsp(a, b, c, Point(0.0f, 10.0f)) << std::endl; // false

  std::cout << "Edges" << std::endl;
  std::cout << bsp(a, b, c, Point(5.0f, 0.0f)) << std::endl; // false
  std::cout << bsp(a, b, c, Point(0.0f, 5.0f)) << std::endl; // false
  std::cout << bsp(a, b, c, Point(5.0f, 5.0f)) << std::endl; // false

  return 0;
}