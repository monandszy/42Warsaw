#include "AMateria.hpp"
#include "Chara.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Chara("me");
  AMateria* tmp1 = src->createMateria("ice");
  me->equip(tmp1);
  AMateria* tmp2 = src->createMateria("cure");
  me->equip(tmp2);
  ICharacter* bob = new Chara("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  me->unequip(0);
  // me->unequip(1);

  delete bob;
  delete me;
  delete src;
  delete tmp1;

  return 0;
}