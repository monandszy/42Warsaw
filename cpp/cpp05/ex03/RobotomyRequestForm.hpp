#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;
  RobotomyRequestForm();

 public:
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat& slave) const;
};
#endif