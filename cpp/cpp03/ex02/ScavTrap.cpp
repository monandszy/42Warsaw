#include "ScavTrap.hpp"

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  if (this != &other) {
    ClapTrap::operator=(other);
  }
  return *this;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other.getName(), other.getHp(), other.getMana(),
               other.getDmg()) {
  (void)other;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "Bye. I was ScavTrap [" << getName() << "]" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "Hi. I'm ScavTrap [" << name << "]" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (ClapTrap::processAttack(target))
    std::cout << "ScavTrap [" << getName() << "] attacks [" << target
              << "] causing [" << getDmg() << "] points of damage!"
              << std::endl;
  else
    std::cout << "[" << getName() << "]: I'm basically dead now, can't attack"
              << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (ClapTrap::processTakeDamage(amount))
    std::cout << "ScavTrap [" << getName() << "] takes [" << amount
              << "] points of damage!" << std::endl;
  else
    std::cout << "[" << getName()
              << "]: I'm basically dead now, can't takeDamage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (ClapTrap::processBeRepaired(amount))
    std::cout << "ScavTrap [" << getName() << "] heals for [" << amount
              << "] points!" << std::endl;
  else
    std::cout << "[" << getName()
              << "]: I'm basically dead now, can't beRepaired" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "[" << getName() << "]: Is guarding?" << std::endl;
}