#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
#include <iomanip>

class Phonebook
{
  private:
    Contact _contacts[8];
  public:
    void print(void);
    Contact& getContact(int index);
    Phonebook(void);
    Phonebook(const Phonebook& other);
    Phonebook& operator=(const Phonebook& other);
    ~Phonebook();
    void add(Contact& contact);
};

#endif
