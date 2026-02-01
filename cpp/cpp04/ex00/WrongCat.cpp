#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
  std::cout << "WrongCat constructor called" << std::endl;
  _type = "WrongCat";
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  if (this != &other) {
    WrongAnimal::operator=(other);
  }
  return *this;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  *this = other;
}

void WrongCat::makeSound(void) const {
  std::cout << getType() << " wrong upper meow catnipfull sound" << std::endl;
}
