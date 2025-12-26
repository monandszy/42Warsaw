#include "ClapTrap.hpp"

int main(void) {
  ClapTrap claptrap("coolest 42 trap");

  claptrap.attack("someone who deserved it");
  claptrap.takeDamage(3);
  claptrap.attack("someone who deserved it more");
  claptrap.beRepaired(1000);
  claptrap.takeDamage(9999969);

  claptrap.attack("someone who can't be attacked anymore");
}