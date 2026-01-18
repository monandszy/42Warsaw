#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other) {
  (void)other;
  return *this;
}

Point::~Point(void) {}

const Fixed& Point::getY() const { return _y; }
const Fixed& Point::getX() const { return _x; }