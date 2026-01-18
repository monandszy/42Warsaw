#include "Dog.hpp"

Dog::~Dog(void) {}

void Dog::makeSound(void) const {
  std::cout << getType() << " bark sound" << std::endl;
}

Dog::Dog(void) : Animal() { Animal::_type = "dog"; }

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Dog::Dog(const Dog& other) : Animal(other) { (void)other; }