#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class WrongAnimal {
  protected:
    std::string _type;
  public:
    WrongAnimal(void);
    ~WrongAnimal(void) = default;
    WrongAnimal& operator=(const WrongAnimal& other) = default;
    WrongAnimal(const WrongAnimal& other) = default;
    void makeSound(void) const;
    std::string getType(void) const;
};
#endif