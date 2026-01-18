
#include "HumanA.hpp"

void HumanA::attack(void) {
  std::cout << _name << " attac smth with " << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon) {
  _name = name;
  // _weapon = weapon;
}

HumanA::HumanA(const HumanA& other) : _weapon(other._weapon) {
  this->_name = other._name;
  // this->_weapon = other._weapon;
}

Weapon& HumanA::getWeapon(void) const { return _weapon; }

HumanA::~HumanA(void) {}

HumanA& HumanA::operator=(const HumanA& other) {
  if (this != &other) {
    this->_name = other._name;
    this->_weapon = other._weapon;
  }
  return *this;
}
