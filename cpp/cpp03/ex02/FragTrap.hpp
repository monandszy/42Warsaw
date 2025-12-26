#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  private:
    FragTrap(void);

  public:
    // FragTrap& operator=(const FragTrap& other);
    // FragTrap(const FragTrap& other);
    ~FragTrap(void);

    FragTrap(std::string name);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void highFivesGuys(void);
};

#endif