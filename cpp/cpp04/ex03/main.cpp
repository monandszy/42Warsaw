#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Chara.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Chara("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Chara("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
  return 0;
}