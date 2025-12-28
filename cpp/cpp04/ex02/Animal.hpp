#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
  protected:
    std::string _type;
    Brain *brain;
  public:
    virtual ~Animal(void);
    virtual Animal& operator=(const Animal& other) = default;
    virtual void makeSound(void) const = 0;
    virtual std::string getType(void) const;
};
#endif