#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
  private:
    int _fpnumval;
    static const int _numofbits = 8;
  public:
    Fixed(void);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(const int raw);
};

#endif