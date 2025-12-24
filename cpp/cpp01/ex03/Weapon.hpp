#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

  private:
    std::string _type;
    Weapon(void);

  public:
    std::string getType(void) const;
    void setType(std::string type);
    
    Weapon(std::string type);
    ~Weapon(void);
    Weapon& operator=(const Weapon& other);
    Weapon(const Weapon& other);
};

#endif