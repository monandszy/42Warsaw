
#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {

}

Cure* Cure::clone() const {
  return new Cure(*this);
}

void Cure::use(ICharacter& target) {
  std::cout << " heals " << target.getName() << "’s wounds *" << std::endl;
}