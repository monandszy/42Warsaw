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
    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif