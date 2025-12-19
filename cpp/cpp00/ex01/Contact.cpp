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

#include "Phonebook.hpp"

class Contact {
  private:
    std::string _contact;

  public:
    const std::string &getContact() const {
      return (_contact);
    }
    Contact() : _contact("Default contact") {
      std::cout << "Contact Default Constructor Called!" << std::endl;
    }
    Contact(const std::string &contact) : _contact(contact) {
      std::cout << "Contact Parameterized Constructor Called!" << std::endl;
    }
    Contact(const Contact &other) : _contact(other._contact) {
      std::cout << "Contact Copy Constructor Called!" << std::endl;
    }
    ~Contact() {
      std::cout << "Contact Destructor Called!" << std::endl;
    }
};