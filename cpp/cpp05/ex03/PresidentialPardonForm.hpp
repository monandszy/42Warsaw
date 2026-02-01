#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;
  PresidentialPardonForm();

 public:
  PresidentialPardonForm(const std::string& target);
  ~PresidentialPardonForm();
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  PresidentialPardonForm(const PresidentialPardonForm& other);

  void execute(const Bureaucrat& slave) const;
};
#endif