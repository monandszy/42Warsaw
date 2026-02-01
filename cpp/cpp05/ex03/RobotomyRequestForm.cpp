#include "RobotomyRequestForm.hpp"

#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

void RobotomyRequestForm::execute(const Bureaucrat& slave) const {
  if (!this->getSigned()) {
    throw FormNotSignedException("FormNotSignedException: " + slave.getName());
  }
  if (slave.getGrade() > this->getExecGrade()) {
    throw InvalidExpertiseException("InvalidExpertiseException: " +
                                    slave.getName());
  }
  std::cout << "* drrrrriiiiiilllllling noises *" << std::endl;
  if (std::rand() % 2) {
    std::cout << _target << " has been robotomized successfully" << std::endl;
  } else {
    std::cout << "Robotomy of " << _target << " failed." << std::endl;
  }
}
