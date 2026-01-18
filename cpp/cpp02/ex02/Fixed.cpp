#include "Fixed.hpp"

const int Fixed::_numofbits = 8;
const int Fixed::_powstep = std::pow(2, Fixed::_numofbits);

Fixed::Fixed(void) { _fpnumval = 0; }

Fixed::Fixed(const Fixed& other) { this->_fpnumval = other._fpnumval; }

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    this->_fpnumval = other._fpnumval;
  }
  return *this;
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const int fpnumval) { _fpnumval = fpnumval * _powstep; }

Fixed::Fixed(const float fpnumval) { _fpnumval = roundf(fpnumval * _powstep); }

float Fixed::toFloat(void) const { return ((float)_fpnumval) / _powstep; }

int Fixed::toInt(void) const { return _fpnumval / _powstep; }

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
  os << other.toFloat();
  return os;
}

int Fixed::getRawBits(void) const { return _fpnumval; }

void Fixed::setRawBits(const int raw) { _fpnumval = raw; }

bool Fixed::operator>(const Fixed& other) const {
  return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const {
  return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const {
  return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
  return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const {
  return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const {
  return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const {
  Fixed result;
  result.setRawBits(this->getRawBits() + other.getRawBits());
  return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
  Fixed result;
  result.setRawBits(this->getRawBits() - other.getRawBits());
  return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
  Fixed result;
  result.setRawBits((long long)this->getRawBits() * other.getRawBits() /
                    _powstep);
  return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
  Fixed result;
  result.setRawBits(this->getRawBits() * _powstep / other.getRawBits());
  return result;
}

Fixed Fixed::operator++(int) {
  Fixed pre(*this);
  _fpnumval++;
  return pre;
}

Fixed& Fixed::operator++() {
  _fpnumval++;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed pre(*this);
  _fpnumval--;
  return pre;
}

Fixed& Fixed::operator--() {
  _fpnumval--;
  return *this;
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
  if (first.getRawBits() < second.getRawBits())
    return (first);
  else
    return (second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
  if (first.getRawBits() < second.getRawBits())
    return (first);
  else
    return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
  if (first.getRawBits() > second.getRawBits())
    return (first);
  else
    return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
  if (first.getRawBits() > second.getRawBits())
    return (first);
  else
    return (second);
}
