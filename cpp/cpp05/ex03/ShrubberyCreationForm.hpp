#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
  public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm() {};
    void execute(const Bureaucrat& slave) const;
};
#endif