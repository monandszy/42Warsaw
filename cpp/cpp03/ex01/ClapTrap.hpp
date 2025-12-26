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

    ClapTrap(std::string name, unsigned int hp, unsigned int mana, unsigned int dmg);

    bool attack(const std::string& target);
    bool takeDamage(unsigned int amount);
    bool beRepaired(unsigned int amount);

    std::string getName(void) const;
    unsigned int getHp(void) const;
    unsigned int getMana(void) const;
    unsigned int getDmg(void) const;
};

#endif