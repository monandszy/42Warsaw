#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  Animal *animal[100];

  for (int i = 0; i < 50; i++) {
    animal[i] = new Dog();
  }

  for (int i = 50; i < 100; i++) {
    animal[i] = new Cat();
  }

  for (int i = 0; i < 100; i++) {
    animal[i]->makeSound();
  }

  for (int i = 0; i < 100; i++) {
    delete animal[i];
  }

  Dog *dog = new Dog();
  Cat *cat = new Cat();
  delete dog;
  delete cat;

  Dog a;
  Dog b(a);

  return 0;
}