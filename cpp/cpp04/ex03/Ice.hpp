#ifndef ICE_HPP
#define ICE_HPP

#include "Chara.hpp"

class Ice : public AMateria
{
  public:
    Ice();
    ~Ice() = default;
    Ice(const Ice& other) = default;
    Ice& operator=(const Ice &other) = default;
    Ice* clone() const;
    void use(ICharacter& target);
};
#endif