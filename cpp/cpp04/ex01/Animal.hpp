#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
  protected:
    std::string _type;
    Brain *brain;
  public:
    Animal(void);
    ~Animal(void);
    Animal& operator=(const Animal& other) = default;
    Animal(const Animal& other) = default;
    void makeSound(void) const;
    std::string getType(void) const;
};
#endif