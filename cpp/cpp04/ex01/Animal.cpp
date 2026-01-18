#include "Animal.hpp"

void Animal::makeSound(void) const {
  std::cout << getType() << " sound" << std::endl;
}

Animal::Animal(void) {
  Animal::_type = "animal";
  _brain = new Brain();
}

Animal::~Animal(void) { delete _brain; }

std::string Animal::getType(void) const { return Animal::_type; }

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    this->_type = other._type;
    if (other._brain) {
      delete this->_brain;
      this->_brain = new Brain(*other._brain);
    }
  }
  return *this;
}

Animal::Animal(const Animal& other) {
  this->_type = other._type;
  if (other._brain) {
    this->_brain = new Brain(*other._brain);
  }
}