#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 private:
  ScavTrap(void);

 public:
  ScavTrap& operator=(const ScavTrap& other);
  ScavTrap(const ScavTrap& other);
  ~ScavTrap(void);

  ScavTrap(std::string name);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void guardGate();
};

#endif