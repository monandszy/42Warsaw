#include "Dog.hpp"

void Dog::makeSound(void) const {
  std::cout << getType() << " bark sound" << std::endl;
}

Dog::Dog(void) : Animal() {
  std::cout << "Dog constructor called" << std::endl;
  Animal::_type = "dog";
}

Dog::~Dog(void) { std::cout << "Dog destructor called" << std::endl; }

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Dog::Dog(const Dog& other) : Animal(other) { (void)other; }