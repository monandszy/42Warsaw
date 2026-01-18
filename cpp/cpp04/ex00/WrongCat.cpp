#include "WrongCat.hpp"

WrongCat& WrongCat::operator=(const WrongCat& other) {
  if (this != &other) {
    WrongAnimal::operator=(other);
  }
  return *this;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) { (void)other; }

void WrongCat::makeSound(void) const {
  std::cout << getType() << " catnipfull sound" << std::endl;
}

WrongCat::WrongCat(void) : WrongAnimal() {
  std::cout << "WrongCat constructor called" << std::endl;
  WrongAnimal::_type = "WrongCat";
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat destructor called" << std::endl;
}
