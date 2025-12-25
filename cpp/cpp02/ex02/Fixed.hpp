#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
  private:
    int _fpnumval;
    static const int _numofbits;
    static const int _powstep;
  public:
    Fixed(void);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed(void);
    Fixed(const int fpnumval);
    Fixed(const float fpnumval);

    int getRawBits(void) const;
    void setRawBits(const int raw);
    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(const Fixed& other);
    bool operator<(const Fixed& other);
    bool operator>=(const Fixed& other);
    bool operator<=(const Fixed& other);
    bool operator==(const Fixed& other);
    bool operator!=(const Fixed& other);

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed operator++(int) const;
    Fixed& operator++();
    Fixed operator--(int) const;
    Fixed& operator--();

    static Fixed& min(Fixed& first, Fixed& second);
    static const Fixed& min(const Fixed& first, const Fixed& second);
    static Fixed& max(Fixed& first, Fixed& second);
    static const Fixed& max(const Fixed& first, const Fixed& second);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif