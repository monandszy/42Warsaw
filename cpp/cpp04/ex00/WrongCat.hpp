#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
  public:
    WrongCat(void);
    void makeSound(void) const;
};
#endif