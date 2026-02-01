#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;
  ShrubberyCreationForm();

 public:
  ShrubberyCreationForm(const std::string& target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);

  void execute(const Bureaucrat& slave) const;
};
#endif