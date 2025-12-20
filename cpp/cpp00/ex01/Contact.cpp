/* 
Contact
Stands for a phonebook contact

Orthodox Canonical Form
- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Assignment Operator
- Destructor
*/

#include "Contact.hpp"

int Contact::getOrder() const
{
  return _order;
}

std::string Contact::getNumber() const
{
  return _number;
}

std::string Contact::getFirstName() const
{
  return _firstName;
}
std::string Contact::getLastName() const
{
  return _lastName;
}
std::string Contact::getNickname() const
{
  return _nickname;
}
std::string Contact::getDarkestSecret() const
{
  return _darkestSecret;
}

Contact::Contact(void)
{
  _number = "[empty]";
  _order = 0;
}

Contact::Contact(std::string number, int order)
{
  _number = number;
  _order = order;
}

Contact::Contact(const Contact &other) 
{
  _number = other._number;
  _order = other._order;
}

Contact &Contact::operator=(const Contact &other) 
{
  if (this != &other) { 
    _number = other._number;
    _order = other._order;
  }
  return *this;
}

Contact::~Contact(void)
{
}
