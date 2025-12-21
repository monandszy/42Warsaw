#include "Zombie.hpp"

Zombie::~Zombie(void)
{
  std::cout << "[LOG] Destroyed Zombie: " << _name << std::endl;
}

Zombie::Zombie(std::string name)
{
  _name = name;
  std::cout << "[LOG] Created Zombie: " << _name << std::endl;
}

Zombie::Zombie(void)
{
  _name = "Catnipfull";
  std::cout << "[LOG] Created Default Zombie: " << _name << std::endl;
}

Zombie::Zombie(const Zombie& other)
{
  *this = other;
}

void Zombie::setName(std::string name)
{
  _name = name;
}

Zombie& Zombie::operator=(const Zombie& other)
{
  if (this != &other) {
    this->_name = other._name;
  }
  return *this;
}

void Zombie::announce(void) const
{
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
