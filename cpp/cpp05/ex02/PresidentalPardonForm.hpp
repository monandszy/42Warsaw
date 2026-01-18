#ifndef Presidential_PARDON_FORM_HPP
#define Presidential_PARDON_FORM_HPP

#include <iostream>

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm();
  ~PresidentialPardonForm(){};
  void execute(const Bureaucrat& slave) const;
};
#endif