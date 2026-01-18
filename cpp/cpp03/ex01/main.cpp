#include "ScavTrap.hpp"

int main(void) {
  ScavTrap trap("coolest 42 trap");

  ScavTrap& trap2 = trap;
  ScavTrap trap3(trap);

  trap.attack("someone who deserved it");
  trap.takeDamage(3);
  trap.attack("someone who deserved it more");
  trap.beRepaired(1000);
  trap.takeDamage(9999969);

  trap.attack("someone who can't be attacked anymore");
  trap.guardGate();

  trap2.takeDamage(1);
  trap3.beRepaired(100);

  ClapTrap* ptr = new ScavTrap("Test");
  ptr->attack("itself");
  delete ptr;
}