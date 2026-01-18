#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria {
 private:
  AMateria();

 protected:
  std::string _type;

 public:
  virtual ~AMateria();
  AMateria(const AMateria& other);
  AMateria& operator=(const AMateria& other);

  AMateria(std::string const& type);
  const std::string& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target) = 0;
};

#endif