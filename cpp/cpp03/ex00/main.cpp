#include "ClapTrap.hpp"

int main(void) {
  ClapTrap claptrap("coolest 42 trap");

  ClapTrap c = claptrap;
  c.beRepaired(1);
  c.takeDamage(9999969);

  claptrap.attack("someone who deserved it");
  claptrap.takeDamage(3);
  claptrap.attack("someone who deserved it more");
  claptrap.beRepaired(1000);
  claptrap.takeDamage(9999969);

  claptrap.attack("someone who can't be attacked anymore");
}