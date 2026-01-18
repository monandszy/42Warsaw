#include "ClapTrap.hpp"

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other) {
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
  std::cout << "Bye. I was ClapTrap [" << _name << "]" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int mana,
                   unsigned int dmg) {
  _name = name;
  _hp = hp;
  _mana = mana;
  _dmg = dmg;
  std::cout << "Hi. I'm ClapTrap [" << _name << "]" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
  _name = name;
  _hp = 10;
  _mana = 10;
  _dmg = 0;
  std::cout << "Hi. I'm [" << _name << "]" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (processAttack(target))
    std::cout << "ClapTrap [" << getName() << "] attacks [" << target
              << "] causing [" << getDmg() << "] points of damage!"
              << std::endl;
  else
    std::cout << "[" << getName() << "]: I'm basically dead now, can't attack"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (processTakeDamage(amount))
    std::cout << "ClapTrap [" << getName() << "] takes [" << amount
              << "] points of damage!" << std::endl;
  else
    std::cout << "[" << getName()
              << "]: I'm basically dead now, can't takeDamage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (processBeRepaired(amount))
    std::cout << "ClapTrap [" << getName() << "] heals for [" << amount
              << "] points!" << std::endl;
  else
    std::cout << "[" << getName()
              << "]: I'm basically dead now, can't beRepaired" << std::endl;
}

bool ClapTrap::processAttack(const std::string& target) {
  (void)target;
  if (_hp > 0 && _mana > 0) {
    _mana--;
    return true;
  }
  return false;
}

bool ClapTrap::processTakeDamage(unsigned int amount) {
  if (_hp > 0) {
    if (_hp < amount)
      _hp = 0;
    else
      _hp -= amount;
    return true;
  }
  return false;
}

bool ClapTrap::processBeRepaired(unsigned int amount) {
  if (_hp > 0 && _mana > 0) {
    _mana--;
    _hp += amount;
    return true;
  }
  return false;
}

std::string ClapTrap::getName(void) const { return _name; }

unsigned int ClapTrap::getHp(void) const { return _hp; }

unsigned int ClapTrap::getMana(void) const { return _mana; }

unsigned int ClapTrap::getDmg(void) const { return _dmg; }

void ClapTrap::setName(const std::string& name) { _name = name; }

void ClapTrap::setHp(unsigned int hp) { _hp = hp; }

void ClapTrap::setMana(unsigned int mana) { _mana = mana; }

void ClapTrap::setDmg(unsigned int dmg) { _dmg = dmg; }
