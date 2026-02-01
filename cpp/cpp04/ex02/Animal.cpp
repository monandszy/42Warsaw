#include "Animal.hpp"

Animal::Animal(void) {
  _type = "animal";
  _brain = new Brain();
}

Animal::~Animal(void) { delete _brain; }

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    this->_type = other._type;
    delete this->_brain;
    this->_brain = new Brain(*other._brain);
  }
  return *this;
}

Animal::Animal(const Animal& other) {
  this->_type = other._type;
  this->_brain = new Brain(*other._brain);
}

const std::string& Animal::getType(void) const { return _type; }