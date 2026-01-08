#include "AForm.hpp"
#include "Bureucrat.hpp"
#include "PresidentalPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm() 
  : Form("PresidentalPardonForm", 25, 5) 
{}

void PresidentalPardonForm::execute(const Bureucrat& slave) const {
  if (!this->getSigned())
    throw FormNotSignedException(slave.getName().c_str());
  std::cout << "---" << slave.getName() 
  << " Informs that " << this->getName() 
  << " has been pardoned by Zaphod Beeblebrox---"
  << std::endl;
}
