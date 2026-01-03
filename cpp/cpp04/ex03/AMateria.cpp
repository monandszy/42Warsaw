#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
  _type = type;
}

const std::string& AMateria::getType() const {
  return _type;
}


