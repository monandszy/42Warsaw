#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat(void);
  ~WrongCat(void);
  WrongCat& operator=(const WrongCat& other);
  WrongCat(const WrongCat& other);
  void makeSound(void) const;
};
#endif