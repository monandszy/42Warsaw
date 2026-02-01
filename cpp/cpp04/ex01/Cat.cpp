#include "Cat.hpp"

Cat::Cat(void) : Animal() {
  std::cout << "Cat constructor called" << std::endl;
  _type = "cat";
  _brain = new Brain();
}

Cat::~Cat(void) {
  std::cout << "Cat destructor called" << std::endl;
  delete _brain;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
    if (other._brain) {
      delete this->_brain;
      this->_brain = new Brain(*other._brain);
    }
  }
  return *this;
}

Cat::Cat(const Cat& other) : Animal(other) {
  Animal::operator=(other);
  this->_brain = new Brain(*other._brain);
}

void Cat::makeSound(void) const {
  std::cout << getType() << " upper meow sound" << std::endl;
}