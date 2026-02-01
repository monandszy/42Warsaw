#include "Cat.hpp"

Cat::Cat(void) : Animal() {
  std::cout << "Cat constructor called" << std::endl;
  _type = "cat";
}

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Cat::Cat(const Cat& other) : Animal(other) { *this = other; }

void Cat::makeSound(void) const {
  std::cout << getType() << " upper meow sound" << std::endl;
}
