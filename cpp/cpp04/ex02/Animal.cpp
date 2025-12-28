#include "Animal.hpp"

Animal::~Animal(void) {
  delete brain;
}

std::string Animal::getType(void) const {
  return Animal::_type;
}