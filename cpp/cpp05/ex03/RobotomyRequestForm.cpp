#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
  : Form("RobotomyRequestForm", 72, 45) 
{}

void RobotomyRequestForm::execute(const Bureaucrat& slave) const {
  if (!this->getSigned())
  {
    std::cout << "Otherwise, it informs that the robotomy failed" << std::endl;
    throw FormNotSignedException(slave.getName().c_str());
  }
  if (!(slave.getGrade() <= this->getExecGrade()))
  {
    std::cout << "Otherwise, it informs that the robotomy failed" << std::endl;
    throw GradeTooLowException(this->getName().c_str());
  }
  std::cout << "---" << slave.getName() 
  << " Makes some drilling noises, then informs that"
  << this->getName() << " has been robotomized successfully 50\% of the time.---"
  << std::endl;
}
