#ifndef HumanB_HPP
#define HumanB_HPP

#include "Weapon.hpp"

class HumanB {

  private:
    std::string _name;
    Weapon* _weapon;
    HumanB(void);

  public:
    Weapon* getWeapon(void) const;
    HumanB(std::string name);
    void attack(void);
    void setWeapon(Weapon& weapon);
    HumanB(std::string name, Weapon* weapon);
    ~HumanB(void);
    HumanB& operator=(const HumanB& other);
    HumanB(HumanB& other);
};

#endif