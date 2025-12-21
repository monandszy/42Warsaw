#include "Weapon.hpp"

void Weapon::setType(std::string type)
{
  _type = type; 
}

std::string Weapon::getType(void) const
{
  return _type;
}

Weapon::Weapon(std::string type)
{
  _type = type;
}

Weapon::Weapon(void)
{
  _type = "default";
}

Weapon::~Weapon(void)
{}

Weapon& Weapon::operator=(const Weapon& other)
{
  if (this != &other)
  {
    this->_type = other._type;
  }
  return *this;
}

Weapon::Weapon(const Weapon& other)
{
  this->_type = other._type;
}
