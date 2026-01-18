#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

void test_bsp(Point const a, Point const b, Point const c, Point const p,
              bool expected, std::string desc) {
  bool result = bsp(a, b, c, p);
  std::cout << desc << ": ";
  if (result == expected)
    std::cout << "OK";
  else
    std::cout << "FAIL (Expected " << expected << ", got " << result << ")";
  std::cout << std::endl;
}

int main(void) {
  Point a(0.0f, 0.0f);
  Point b(10.0f, 0.0f);
  Point c(0.0f, 10.0f);

  // Triangle: (0,0) - (10,0) - (0,10)
  // Inside
  test_bsp(a, b, c, Point(1.0f, 1.0f), true, "Inside (1,1)");
  test_bsp(a, b, c, Point(2.0f, 2.0f), true, "Inside (2,2)");

  // Outside
  test_bsp(a, b, c, Point(10.0f, 10.0f), false, "Outside (10,10) far");
  test_bsp(a, b, c, Point(-1.0f, -1.0f), false, "Outside (-1,-1) negative");

  // Vertices - Should be false
  test_bsp(a, b, c, Point(0.0f, 0.0f), false, "Vertex A (0,0)");
  test_bsp(a, b, c, Point(10.0f, 0.0f), false, "Vertex B (10,0)");
  test_bsp(a, b, c, Point(0.0f, 10.0f), false, "Vertex C (0,10)");

  // Edges - Should be false
  test_bsp(a, b, c, Point(5.0f, 0.0f), false, "Edge A-B (5,0)");
  test_bsp(a, b, c, Point(0.0f, 5.0f), false, "Edge A-C (0,5)");
  test_bsp(a, b, c, Point(5.0f, 5.0f), false, "Edge B-C (5,5)");

  return 0;
}