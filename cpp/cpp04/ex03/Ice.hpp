#ifndef ICE_HPP
#define ICE_HPP

#include "Chara.hpp"

class Ice : public AMateria {
 public:
  Ice();
  ~Ice();
  Ice(const Ice& other);
  Ice& operator=(const Ice& other);
  Ice* clone() const;
  void use(ICharacter& target);
};
#endif