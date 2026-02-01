#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const& type) { _type = type; }

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

AMateria::AMateria(const AMateria& other) { *this = other; }

const std::string& AMateria::getType() const { return _type; }
