#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
 protected:
  Brain* _brain;

 public:
  Cat(void);
  ~Cat(void);
  Cat& operator=(const Cat& other);
  Cat(const Cat& other);
  void makeSound(void) const;
};
#endif