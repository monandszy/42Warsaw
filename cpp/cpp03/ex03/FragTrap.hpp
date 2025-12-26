#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
  private:
    FragTrap(void);

  public:
    ~FragTrap(void);

    FragTrap(std::string name);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void highFivesGuys(void);
};

#endif