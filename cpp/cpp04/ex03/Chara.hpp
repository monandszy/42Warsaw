#ifndef CHARA_HPP
#define CHARA_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
  public:
    virtual ~ICharacter() {};
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Chara : public ICharacter
{
  private:
    std::string _name;
    AMateria* _eq[4];
    Chara() = default;

  public:
    ~Chara();
    Chara(const Chara& other);
    Chara& operator=(const Chara& other);
    
    Chara(const std::string& name);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif