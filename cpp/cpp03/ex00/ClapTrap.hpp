#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
 private:
  std::string _name;
  unsigned int _hp;
  unsigned int _mana;
  unsigned int _dmg;
  ClapTrap(void);

 public:
  ClapTrap& operator=(const ClapTrap& other);
  ClapTrap(const ClapTrap& other);
  ~ClapTrap(void);

  ClapTrap(std::string name);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif