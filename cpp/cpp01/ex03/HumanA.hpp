#ifndef HumanA_HPP
#define HumanA_HPP

#include "Weapon.hpp"

class HumanA {
 private:
  std::string _name;
  Weapon& _weapon;
  HumanA(void);

 public:
  Weapon& getWeapon(void) const;
  void attack(void);

  HumanA(std::string name, Weapon& weapon);
  ~HumanA(void);
  HumanA& operator=(const HumanA& other);
  HumanA(const HumanA& other);
};

#endif