#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
  Animal *animal[100];

  for(int i = 0; i < 50; i++)
  {
    animal[i] = new Dog();
  }

  for(int i = 50; i < 100; i++)
  {
    animal[i] = new Cat();
  }

  for(int i = 0; i < 100; i++)
  {
    animal[i]->makeSound();
  }
  
  for(int i = 0; i < 100; i++)
  {
    delete animal[i];
  }
  return 0;
}