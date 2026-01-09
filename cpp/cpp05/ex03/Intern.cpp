#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
  (void) other;
}

Intern& Intern::operator=(const Intern& other) {
  (void) other;
  return (*this);
}

Form& Intern::presidential()
{
  PresidentialPardonForm *pf = new PresidentialPardonForm();
  Form &f = *pf;
  return (f);
}

Form& Intern::robotomy()
{
  RobotomyRequestForm *rf = new RobotomyRequestForm();
  Form &f = *rf;
  return (f);
}

Form& Intern::shrubbery()
{
  ShrubberyCreationForm *sf = new ShrubberyCreationForm();
  Form &f = *sf;
  return (f);
}


Form& Intern::makeForm(std::string key) {
  static Entry table[] = {
    {"presidential", &Intern::presidential},
    {"robotomy", &Intern::robotomy},
    {"shrubbery", &Intern::shrubbery},
    {NULL,    NULL} 
  };

  int i = 0;

  while(table[i].key)
  {
    if (std::string(table[i].key) == key)
    {
      return (this->*table[i].value)();
    }
    i++;
  }
  throw std::invalid_argument( "form not found" );
}
