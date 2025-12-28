#include "WrongAnimal.hpp"

void WrongAnimal::makeSound(void) const {
  std::cout << getType() << " 42 sound" << std::endl;
}

WrongAnimal::WrongAnimal(void) {
  WrongAnimal::_type = "null";
}

std::string WrongAnimal::getType(void) const {
  return WrongAnimal::_type;
}