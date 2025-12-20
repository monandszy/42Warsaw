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

void Phonebook::add(Contact& contact)
{
  int order = _contacts[1].getOrder();
  int chosen = 0;

  for (int i = 1; i < 8; i++)
  {
    if(_contacts[i].getOrder() < order)
    {
      order = _contacts[i].getOrder();
      chosen = i;
    }
  }
  _contacts[chosen] = contact;
}

void fprint(std::string str)
{
  if (str.length() > 10)
  {
    str = str.substr(0, 9);
    str = str + ".";
  }
  std::cout << std::setw(10) << std::right << str << "|";
}

void Phonebook::print(void)
{
  for (int i = 0; i < 8; i++)
  {
    Contact contact = _contacts[i];
    std::cout << "|";
    std::cout << std::setw(10) << std::right << i << "|";
    fprint(contact.getNumber());
    fprint(contact.getFirstName());
    fprint(contact.getLastName());
    fprint(contact.getNickname());
    std::cout << std::endl;
  }
}

