#include "FragTrap.hpp"

int main(void) {
  std::string name = "coolest 42 trap";
  FragTrap trap(name);

  FragTrap& trap2 = trap;
  FragTrap trap3(trap);

  trap.attack("someone who deserved it");
  trap.takeDamage(3);
  trap.attack("someone who deserved it more");
  trap.beRepaired(1000);
  trap.takeDamage(9999969);

  trap.attack("someone who can't be attacked anymore");
  trap.highFivesGuys();

  trap2.takeDamage(1);
  trap3.beRepaired(100);
}