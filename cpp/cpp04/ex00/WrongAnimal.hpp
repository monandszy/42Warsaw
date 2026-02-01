#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
 protected:
  std::string _type;

 public:
  WrongAnimal(void);
  ~WrongAnimal(void);
  WrongAnimal& operator=(const WrongAnimal& other);
  WrongAnimal(const WrongAnimal& other);
  void makeSound(void) const;
  const std::string& getType(void) const;
};
#endif