#include "Animal.hpp"

Animal::Animal(void) {
  std::cout << "Animal constructor called" << std::endl;
  _type = "animal";
}

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

const std::string& Animal::getType(void) const { return _type; }