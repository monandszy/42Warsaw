#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  private:
    const Fixed _x;
    const Fixed _y;
  
  public:
    Point();
    Point(Fixed x, Fixed y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
};

#endif