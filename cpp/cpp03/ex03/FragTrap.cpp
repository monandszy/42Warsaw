#include "FragTrap.hpp"

FragTrap::~FragTrap(void) {
  std::cout << "Bye. I was FragTrap ["<< getName() <<"]" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "Hi. I'm FragTrap ["<< name <<"]" << std::endl;
}

void FragTrap::attack(const std::string& target) {
  if (ClapTrap::processAttack(target))
    std::cout << "FragTrap [" << getName() << "] attacks [" << target << "] causing [" << getDmg() << "] points of damage!" << std::endl;
  else 
    std::cout << "[" << getName() << "]: I'm basically dead now, can't attack" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
  if (ClapTrap::processTakeDamage(amount))
    std::cout << "FragTrap [" << getName() << "] takes [" << amount << "] points of damage!" << std::endl;
  else
    std::cout << "[" << getName() << "]: I'm basically dead now, can't takeDamage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
  if (ClapTrap::processBeRepaired(amount))
    std::cout << "FragTrap [" << getName() << "] heals for [" << amount << "] points!" << std::endl;
  else
    std::cout << "[" << getName() << "]: I'm basically dead now, can't beRepaired" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "[" << getName() << "]: High Five?" << std::endl;
}