#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    _eq[i] = NULL;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++)
    if(_eq[i])
      delete _eq[i];
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  for (int i = 0; i < 4; i++)
    if(other._eq[i])
      this->_eq[i] = other._eq[i]->clone();
    else
      this->_eq[i] = NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  if (&other != this)
  {
    for (int i = 0; i < 4; i++)
    if(other._eq[i])
      this->_eq[i] = other._eq[i]->clone();
    else
      this->_eq[i] = NULL;
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < 4; i++)
    if(!_eq[i])
    {
      _eq[i] = m;
      break;
    }
}

AMateria* MateriaSource::createMateria(std::string const & s) {
  for (int i = 0; i < 4; i++)
    if(_eq[i] && _eq[i]->getType() == s)
      return _eq[i]->clone();
  return (0);
}
