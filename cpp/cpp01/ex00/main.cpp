#include "Zombie.hpp"

int main(void)
{
  Zombie* z = newZombie("Catium1");
  randomChump("Catium2");

  z->announce();
  delete z;
}