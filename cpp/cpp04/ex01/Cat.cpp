#include "Cat.hpp"

Cat::~Cat(void) {}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Cat::Cat(const Cat& other) : Animal(other) { (void)other; }

void Cat::makeSound(void) const {
  std::cout << getType() << " meow sound" << std::endl;
}

Cat::Cat(void) : Animal() { Animal::_type = "cat"; }