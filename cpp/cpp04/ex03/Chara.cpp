#include "Chara.hpp"

Chara::Chara() {}

Chara::~Chara() {
  for (int i = 0; i < 4; i++)
    if (_eq[i]) delete _eq[i];
}

Chara::Chara(const Chara& other) {
  this->_name = other._name;
  for (int i = 0; i < 4; i++)
    if (other._eq[i])
      this->_eq[i] = other._eq[i]->clone();
    else
      this->_eq[i] = NULL;
}

Chara& Chara::operator=(const Chara& other) {
  if (&other != this) {
    this->_name = other._name;
    for (int i = 0; i < 4; i++)
      if (_eq[i]) delete _eq[i];
    for (int i = 0; i < 4; i++)
      if (other._eq[i])
        this->_eq[i] = other._eq[i]->clone();
      else
        this->_eq[i] = NULL;
  }
  return *this;
}

Chara::Chara(const std::string& name) {
  _name = name;
  for (int i = 0; i < 4; i++) _eq[i] = NULL;
}

std::string const& Chara::getName() const { return _name; }

void Chara::equip(AMateria* m) {
  for (int i = 0; i < 4; i++)
    if (!_eq[i]) {
      _eq[i] = m;
      break;
    }
}

void Chara::unequip(int idx) {
  if (idx >= 0 && idx <= 3 && _eq[idx]) _eq[idx] = NULL;
}

void Chara::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx <= 3 && _eq[idx]) _eq[idx]->use(target);
}
