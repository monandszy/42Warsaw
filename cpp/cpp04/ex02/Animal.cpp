#include "Animal.hpp"

Animal::Animal(void) {
  Animal::_type = "animal";
  _brain = new Brain();
}

Animal::~Animal(void) { delete _brain; }

std::string Animal::getType(void) const { return Animal::_type; }

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    this->_type = other._type;
    delete this->_brain;
    if (other._brain) {
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