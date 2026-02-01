#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  const Animal* meta = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();
  std::cout << std::endl;

  std::cout << dog->getType() << std::endl;
  std::cout << cat->getType() << std::endl;
  std::cout << std::endl;

  cat->makeSound();
  dog->makeSound();
  meta->makeSound();
  std::cout << std::endl;

  delete meta;
  delete dog;
  delete cat;
  std::cout << std::endl;

  const WrongAnimal* wmeta = new WrongAnimal();
  const WrongAnimal* wcat = new WrongCat();
  std::cout << std::endl;

  std::cout << wcat->getType() << std::endl;
  std::cout << wmeta->getType() << std::endl;
  std::cout << std::endl;

  wcat->makeSound();
  wmeta->makeSound();
  std::cout << std::endl;

  delete wmeta;
  delete wcat;

  return 0;
}