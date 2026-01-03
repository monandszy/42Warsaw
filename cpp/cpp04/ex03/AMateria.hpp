#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
  private:
    AMateria() = default;

  protected:
    std::string _type;
    
  public:
    virtual ~AMateria() = default;
    AMateria(const AMateria& other) = default;
    AMateria& operator=(const AMateria &other) = default;

    AMateria(std::string const & type);
    const std::string& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};

#endif