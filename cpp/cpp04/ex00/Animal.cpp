#include "Animal.hpp"

Animal::~Animal(void) { std::cout << "Animal destructor called" << std::endl; }

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

Animal::Animal(const Animal& other) { this->_type = other._type; }

void Animal::makeSound(void) const {
  std::cout << getType() << " sound" << std::endl;
}

Animal::Animal(void) {
  std::cout << "Animal constructor called" << std::endl;
  Animal::_type = "animal";
}

std::string Animal::getType(void) const { return Animal::_type; }