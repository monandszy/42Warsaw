#include "Cat.hpp"

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

Cat::Cat(void) : Animal() {
  std::cout << "Cat constructor called" << std::endl;
  Animal::_type = "cat";
}

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }
