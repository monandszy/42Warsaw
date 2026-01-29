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
  virtual ~ClapTrap(void);

  ClapTrap(const std::string& name, unsigned int hp, unsigned int mana,
           unsigned int dmg);
  ClapTrap(const std::string& name);

  virtual void attack(const std::string& target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);

  const std::string& getName(void) const;
  unsigned int getHp(void) const;
  unsigned int getMana(void) const;
  unsigned int getDmg(void) const;

 protected:
  void setName(const std::string& name);
  void setHp(unsigned int hp);
  void setMana(unsigned int mana);
  void setDmg(unsigned int dmg);
  bool processAttack(const std::string& target);
  bool processTakeDamage(unsigned int amount);
  bool processBeRepaired(unsigned int amount);
};

#endif