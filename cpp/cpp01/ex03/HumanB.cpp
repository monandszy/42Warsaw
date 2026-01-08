#include "HumanB.hpp"

void HumanB::attack(void)
{
  if (_weapon)
    std::cout << _name << " attac smth with " << _weapon->getType() << std::endl;
  else
    std::cout << _name << " tires to attac but can't" << std::endl;
}

HumanB::HumanB(std::string name, Weapon* weapon)
{
  _weapon = weapon;
  _name = name;
}

void HumanB::setWeapon(Weapon& weapon)
{
  _weapon = &weapon;
}

Weapon* HumanB::getWeapon(void) const
{
  return _weapon;
}

HumanB::HumanB(std::string name)
{
  _weapon = NULL;
  _name = name;
}

HumanB::HumanB(void)
{
  _weapon = NULL;
  _name = "B";
}

HumanB::~HumanB(void)
{}

HumanB& HumanB::operator=(const HumanB& other)
{
  if (this != &other)
  {
    this->_name = other._name;
    this->_weapon = other._weapon;
  }
  return *this;
}

HumanB::HumanB(const HumanB& other)
{
  this->_name = other._name;
  this->_weapon = other._weapon;
}
