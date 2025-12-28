#include "Animal.hpp"

void Animal::makeSound(void) const {
  std::cout << getType() << " sound" << std::endl;
}

Animal::Animal(void) {
  Animal::_type = "animal";
}

std::string Animal::getType(void) const {
  return Animal::_type;
}