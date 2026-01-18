#include "Fixed.hpp"

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  _fpnumval = 0;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  this->_fpnumval = other._fpnumval;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->_fpnumval = other._fpnumval;
  }
  return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _fpnumval;
}

void Fixed::setRawBits(const int raw) { _fpnumval = raw; }