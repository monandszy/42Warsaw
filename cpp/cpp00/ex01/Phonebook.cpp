#include "Phonebook.hpp"

Phonebook::Phonebook(void) {

}

Contact& Phonebook::getContact(int index) {
  return _contacts[index];
}

Phonebook::Phonebook(const Phonebook& other) {
  *this = other;
}

Phonebook& Phonebook::operator=(const Phonebook& other) {
  if (this != &other) {
    for (int i = 0; i < 8; i++) {
      this->_contacts[i] = other._contacts[i];
    }
  }
  return *this;
}

Phonebook::~Phonebook() {}
