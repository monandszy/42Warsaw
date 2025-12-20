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
  _firstName = "[empty]";
  _lastName = "[empty]";
  _nickname = "[empty]";
  _darkestSecret = "[empty]";
  _order = 0;
}

Contact::Contact(
  int order,
  std::string number,
  std::string firstName,
  std::string lastName,
  std::string nickname,
  std::string darkestSecret
)
{
  _number = number;
  _firstName = firstName;
  _lastName = lastName;
  _nickname = nickname;
  _darkestSecret = darkestSecret;
  _order = order;
}

Contact::Contact(const Contact &other) 
{
  _number = other._number;
  _firstName = other._firstName;
  _lastName = other._lastName;
  _nickname = other._nickname;
  _darkestSecret = other._darkestSecret;
  _order = other._order;
}

Contact &Contact::operator=(const Contact &other) 
{
  if (this != &other) { 
    _number = other._number;
    _firstName = other._firstName;
    _lastName = other._lastName;
    _nickname = other._nickname;
    _darkestSecret = other._darkestSecret;
    _order = other._order;
  }
  return *this;
}

Contact::~Contact(void)
{
}
