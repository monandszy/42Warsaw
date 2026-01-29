#include "Fixed.hpp"

const int Fixed::_numofbits = 8;
const int Fixed::_powstep = std::pow(2, Fixed::_numofbits);

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  _fpnumval = 0;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  this->_fpnumval = other._fpnumval;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Assignment operator called" << std::endl;
  if (this != &other) {
    this->_fpnumval = other._fpnumval;
  }
  return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const int fpnumval) {
  std::cout << "Int constructor called" << std::endl;
  _fpnumval = fpnumval * _powstep;
}

Fixed::Fixed(const float fpnumval) {
  std::cout << "Float constructor called" << std::endl;
  _fpnumval = roundf(fpnumval * _powstep);
}

float Fixed::toFloat(void) const { return ((float)_fpnumval) / _powstep; }

int Fixed::toInt(void) const { return _fpnumval / _powstep; }

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
  os << other.toFloat();
  return os;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _fpnumval;
}

void Fixed::setRawBits(const int raw) { _fpnumval = raw; }