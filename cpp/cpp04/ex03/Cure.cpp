
#include "Cure.hpp"

#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other) {
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}

Cure::Cure(const Cure& other) : AMateria(other) { *this = other; }

Cure* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target) {
  std::cout << " heals " << target.getName() << "’s wounds *" << std::endl;
}