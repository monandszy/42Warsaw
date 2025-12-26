#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap(void) {
  std::cout << "Bye. I was DiamondTrap ["<< _name <<"]" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
: ClapTrap(name + "_clap_name"),
  FragTrap(name + "_clap_name"),
  ScavTrap(name + "_clap_name")
{
  _name = name;
  setHp(100);
  setMana(50);
  setDmg(30);
  std::cout << "Hi. I'm DiamondTrap ["<< name <<"]" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
  if (ClapTrap::processTakeDamage(amount))
    std::cout << "DiamondTrap [" << _name << "] takes [" << amount << "] points of damage!" << std::endl;
  else
    std::cout << "[" << _name << "]: I'm basically dead now, can't takeDamage" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
  if (ClapTrap::processBeRepaired(amount))
    std::cout << "DiamondTrap [" << _name << "] heals for [" << amount << "] points!" << std::endl;
  else
    std::cout << "[" << _name << "]: I'm basically dead now, can't beRepaired" << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "I, DiamondTrap [" << _name << "] contain the almighty [" << ClapTrap::getName() << "]" << std::endl;
}
