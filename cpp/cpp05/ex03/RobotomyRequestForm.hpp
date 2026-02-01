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
  ~RobotomyRequestForm();
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  RobotomyRequestForm(const RobotomyRequestForm& other);

  void execute(const Bureaucrat& slave) const;
};
#endif