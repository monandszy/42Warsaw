#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
  public:
    RobotomyRequestForm();
    ~RobotomyRequestForm() {};
    void execute(const Bureaucrat& slave) const;
};
#endif