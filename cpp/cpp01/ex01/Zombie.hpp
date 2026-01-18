#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
 private:
  std::string _name;

 public:
  void setName(std::string name);
  void announce(void) const;
  Zombie(std::string name);
  Zombie(const Zombie& other);
  Zombie& operator=(const Zombie& other);
  ~Zombie(void);
  Zombie(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif