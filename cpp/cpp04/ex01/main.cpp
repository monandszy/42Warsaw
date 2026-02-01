#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  Animal* animal[100];

  for (int i = 0; i < 50; i++) {
    animal[i] = new Dog();
    std::cout << std::endl;
  }

  for (int i = 50; i < 100; i++) {
    animal[i] = new Cat();
    std::cout << std::endl;
  }

  for (int i = 0; i < 100; i++) {
    animal[i]->makeSound();
    std::cout << std::endl;
  }

  for (int i = 0; i < 100; i++) {
    delete animal[i];
    std::cout << std::endl;
  }

  Dog* dog = new Dog();
  Cat* cat = new Cat();
  delete dog;
  delete cat;

  Dog a;
  Dog b(a);

  return 0;
}