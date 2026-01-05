#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}

Point& Point::operator=(const Point& other) {
  return (Point&) other;
}

Point::~Point(void) {
}