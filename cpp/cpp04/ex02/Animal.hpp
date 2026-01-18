#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"

class Animal {
 protected:
  std::string _type;
  Brain* _brain;

 public:
  Animal(void);
  virtual ~Animal(void);
  Animal& operator=(const Animal& other);
  Animal(const Animal& other);
  virtual void makeSound(void) const = 0;
  std::string getType(void) const;
};
#endif