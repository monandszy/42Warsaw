#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {

}

Ice* Ice::clone() const {
  return new Ice(*this);
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}