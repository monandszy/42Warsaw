#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
  std::cout << "WrongAnimal constructor called" << std::endl;
  _type = "null";
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) { *this = other; }

void WrongAnimal::makeSound(void) const {
  std::cout << getType() << " animal 42 sound" << std::endl;
}

const std::string& WrongAnimal::getType(void) const { return _type; }