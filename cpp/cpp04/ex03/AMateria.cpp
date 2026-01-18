#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) { _type = type; }

const std::string& AMateria::getType() const { return _type; }

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) { this->_type = other._type; }

AMateria& AMateria::operator=(const AMateria& other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}