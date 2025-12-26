#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void) {
  std::cout << "Bye. I was ScavTrap ["<< getName() <<"]" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "Hi. I'm ScavTrap ["<< name <<"]" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (ClapTrap::attack(target))
    std::cout << "ScavTrap [" << getName() << "] attacks [" << target << "] causing [" << getDmg() << "] points of damage!" << std::endl;
  else 
    std::cout << "[" << getName() << "]: I'm basically dead now, can't attack" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (ClapTrap::takeDamage(amount))
    std::cout << "ScavTrap [" << getName() << "] takes [" << amount << "] points of damage!" << std::endl;
  else
    std::cout << "[" << getName() << "]: I'm basically dead now, can't takeDamage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (ClapTrap::beRepaired(amount))
    std::cout << "ScavTrap [" << getName() << "] heals for [" << amount << "] points!" << std::endl;
  else
    std::cout << "[" << getName() << "]: I'm basically dead now, can't beRepaired" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "[" << getName() << "]: Is guarding?" << std::endl;
}