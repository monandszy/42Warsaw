#ifndef CURE_HPP
#define CURE_HPP

#include "Chara.hpp"

class Cure : public AMateria
{
  public:
    Cure();
    ~Cure() = default;
    Cure(const Cure& other) = default;
    Cure& operator=(const Cure &other) = default;
    virtual Cure* clone() const;
    virtual void use(ICharacter& target);
};
#endif