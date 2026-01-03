#include "Cat.hpp"

void Cat::makeSound(void) const {
  std::cout << getType() << " meow sound" << std::endl;
}

Cat::Cat(void) : Animal() {
  Animal::_type = "cat";
}