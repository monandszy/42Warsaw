#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap trap("coolest 42 trap");

  DiamondTrap& trap2 = trap;
  DiamondTrap trap3(trap);

  trap.attack("someone who deserved it");
  trap.takeDamage(3);
  trap.attack("someone who deserved it more");
  trap.beRepaired(1000);
  trap.takeDamage(9999969);

  trap.attack("someone who can't be attacked anymore");
  trap.whoAmI();

  trap2.takeDamage(1);
  trap3.beRepaired(100);
}