#ifndef INTERN_HPP
#define INTERN_HPP

class Form;

#include <iostream>

class Intern 
{
  private:
    Form& presidential();
    Form& robotomy();
    Form& shrubbery();

  struct Entry {
    const char *key;
    Form& (Intern::*value)();
  };

  public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator =(const Intern& other);
    Form& makeForm(std::string key);
};

#endif