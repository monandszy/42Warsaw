#include "Cat.hpp"

Cat::Cat(void) : Animal() { _type = "cat"; }

Cat::~Cat(void) {}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Cat::Cat(const Cat& other) : Animal(other) { *this = other; }

void Cat::makeSound(void) const {
  std::cout << getType() << " meow sound" << std::endl;
}
