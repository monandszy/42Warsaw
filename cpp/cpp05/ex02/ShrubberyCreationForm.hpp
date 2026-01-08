#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureucrat;

class ShrubberyCreationForm : public Form
{
  public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm() {};
    void execute(const Bureucrat& slave) const;
};
#endif