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
  std::cout << "Bye. I was ["<< _name <<"]" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
  _name = name;
  _hp = 10;
  _mana = 10;
  _dmg = 0;
  std::cout << "Hi. I'm ["<< _name <<"]" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (_hp > 0 && _mana > 0)
  {
    std::cout << "ClapTrap [" << _name << "] attacks [" << target << "] causing [" << _dmg << "] points of damage!" << std::endl;
    _mana--;
  } else
   std::cout << "[" << _name << "]: I'm basically dead now, can't attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hp > 0)
  {
    std::cout << "ClapTrap [" << _name << "] takes [" << amount << "] points of damage!" << std::endl;
    if (_hp < amount)
      _hp = 0;
    else
      _hp -= amount;
  }
  else
    std::cout << "[" << _name << "]: I'm basically dead now, can't takeDamage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hp > 0 && _mana > 0)
  {
    std::cout << "ClapTrap [" << _name << "] heals for [" << amount << "] points!" << std::endl;
    _mana--;
    _hp += amount;
  } else
    std::cout << "[" << _name << "]: I'm basically dead now, can't beRepaired" << std::endl;
}