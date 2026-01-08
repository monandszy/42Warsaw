#include "AForm.hpp"
#include "Bureucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
  : Form("RobotomyRequestForm", 72, 45) 
{}

void RobotomyRequestForm::execute(const Bureucrat& slave) const {
  if (!this->getSigned())
    throw FormNotSignedException(slave.getName().c_str());
  std::cout << "---" << slave.getName() 
  << " Makes some drilling noises, then informs that"
  << this->getName() << " has been robotomized successfully 50\% of the time."
  << "Otherwise, it informs that the robotomy failed.---"
  << std::endl;
}
