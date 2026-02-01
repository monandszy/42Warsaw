#include "Dog.hpp"

Dog::Dog(void) : Animal() {
  std::cout << "Dog constructor called" << std::endl;
  _type = "dog";
  _brain = new Brain();
}

Dog::~Dog(void) {
  std::cout << "Dog destructor called" << std::endl;
  delete _brain;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
    if (other._brain) {
      delete this->_brain;
      this->_brain = new Brain(*other._brain);
    }
  }
  return *this;
}

Dog::Dog(const Dog& other) : Animal(other) {
  Animal::operator=(other);
  this->_brain = new Brain(*other._brain);
}

void Dog::makeSound(void) const {
  std::cout << getType() << " upper bark sound" << std::endl;
}