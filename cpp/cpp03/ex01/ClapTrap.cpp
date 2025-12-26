#include "ClapTrap.hpp"

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other)
  {
    this->_name = other._name;
    this->_hp = other._hp;
    this->_mana = other._mana;
    this->_dmg = other._dmg;
  }
  return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
  this->_name = other._name;
  this->_hp = other._hp;
  this->_mana = other._mana;
  this->_dmg = other._dmg;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "Bye. I was ClapTrap ["<< _name <<"]" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int mana, unsigned int dmg) {
  _name = name;
  _hp = hp;
  _mana = mana;
  _dmg = dmg;
  std::cout << "Hi. I'm ClapTrap ["<< _name <<"]" << std::endl;
}

bool ClapTrap::attack(const std::string& target) {
  (void) target;
  if (_hp > 0 && _mana > 0)
  {
    _mana--;
    return true;
  }
  return false;
}

bool ClapTrap::takeDamage(unsigned int amount) {
  if (_hp > 0)
  {
    if (_hp < amount)
      _hp = 0;
    else
      _hp -= amount;
    return true;
  }
  return false;
}

bool ClapTrap::beRepaired(unsigned int amount) {
  if (_hp > 0 && _mana > 0)
  {
    _mana--;
    _hp += amount;
    return true;
  }
  return false;
}

std::string ClapTrap::getName(void) const {
  return _name;
}

unsigned int ClapTrap::getHp(void) const {
  return _hp;
}

unsigned int ClapTrap::getMana(void) const {
  return _mana;
}

unsigned int ClapTrap::getDmg(void) const {
  return _dmg;
}

