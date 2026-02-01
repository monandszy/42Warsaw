#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"

class Animal {
 protected:
  std::string _type;

 public:
  Animal(void);
  virtual ~Animal(void);
  Animal& operator=(const Animal& other);
  Animal(const Animal& other);
  virtual void makeSound(void) const;
  virtual const std::string& getType(void) const;
};
#endif