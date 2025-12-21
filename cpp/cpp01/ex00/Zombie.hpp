#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

  private:
    std::string _name;
    Zombie(void);

  public:
    void announce(void) const;
    Zombie(std::string name);
    Zombie(const Zombie& other);
    Zombie& operator=(const Zombie& other);
    ~Zombie(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif