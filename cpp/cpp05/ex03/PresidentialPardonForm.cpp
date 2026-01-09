#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
  : Form("PresidentialPardonForm", 25, 5) 
{}

void PresidentialPardonForm::execute(const Bureaucrat& slave) const {
  if (!this->getSigned())
    throw FormNotSignedException(slave.getName().c_str());
  if (!(slave.getGrade() <= this->getExecGrade()))
    throw GradeTooLowException(this->getName().c_str());
  std::cout << "---" << slave.getName() 
  << " Informs that " << this->getName() 
  << " has been pardoned by Zaphod Beeblebrox---"
  << std::endl;
}
