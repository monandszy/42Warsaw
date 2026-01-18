#include "WrongAnimal.hpp"

void WrongAnimal::makeSound(void) const {
  std::cout << getType() << " 42 sound" << std::endl;
}

WrongAnimal::WrongAnimal(void) {
  std::cout << "WrongAnimal constructor called" << std::endl;
  WrongAnimal::_type = "null";
}

std::string WrongAnimal::getType(void) const { return WrongAnimal::_type; }

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
  this->_type = other._type;
}
