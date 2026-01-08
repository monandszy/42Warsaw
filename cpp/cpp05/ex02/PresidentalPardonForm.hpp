#ifndef PRESIDENTAL_PARDON_FORM_HPP
#define PRESIDENTAL_PARDON_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureucrat;

class PresidentalPardonForm : public Form
{
  public:
    PresidentalPardonForm();
    ~PresidentalPardonForm() {};
    void execute(const Bureucrat& slave) const;
};
#endif