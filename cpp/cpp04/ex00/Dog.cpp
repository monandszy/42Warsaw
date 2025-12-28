#include "Dog.hpp"

void Dog::makeSound(void) const {
  std::cout << getType() << "dog sound" << std::endl;
}

Dog::Dog(void) : Animal() {
  Animal::_type = "dog";
}