#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  DiamondTrap(void);
  std::string _name;

 public:
  DiamondTrap& operator=(const DiamondTrap& other);
  DiamondTrap(const DiamondTrap& other);
  ~DiamondTrap(void);

  DiamondTrap(std::string name);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void whoAmI(void);
};

#endif