#include "WrongCat.hpp"

void WrongCat::makeSound(void) const {
  std::cout << getType() << " catnipfull sound" << std::endl;
}


WrongCat::WrongCat(void) : WrongAnimal() {
  WrongAnimal::_type = "WrongCat";
}