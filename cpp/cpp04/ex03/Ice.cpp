#include "Ice.hpp"

#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other) {
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}

Ice::Ice(const Ice& other) : AMateria(other) { *this = other; }

Ice* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}