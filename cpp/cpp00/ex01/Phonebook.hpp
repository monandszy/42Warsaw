#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class Phonebook
{
  private:
    Contact _contacts[8];
  public:
    Contact& getContact(int index);
    Phonebook(void);
    Phonebook(const Phonebook& other);
    Phonebook& operator=(const Phonebook& other);
    ~Phonebook();
};

#endif
