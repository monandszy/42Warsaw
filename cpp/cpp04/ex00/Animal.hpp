#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
  protected:
    std::string _type;
  public:
    Animal(void);
    ~Animal(void) = default;
    Animal& operator=(const Animal& other) = default;
    Animal(const Animal& other) = default;
    void makeSound(void) const;
    std::string getType(void) const;
};
#endif