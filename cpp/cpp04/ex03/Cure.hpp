#ifndef CURE_HPP
#define CURE_HPP

#include "Chara.hpp"

class Cure : public AMateria {
 public:
  Cure();
  ~Cure();
  Cure(const Cure& other);
  Cure& operator=(const Cure& other);
  virtual Cure* clone() const;
  virtual void use(ICharacter& target);
};
#endif