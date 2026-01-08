#include "AForm.hpp"
#include "Bureucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
  : Form("ShrubberyCreationForm", 145, 137) 
{}

void ShrubberyCreationForm::execute(const Bureucrat& slave) const {
  if (!this->getSigned())
    throw FormNotSignedException(slave.getName().c_str());
  std::cout << "---" << slave.getName() 
  << " Creates a file " << this->getName() 
  << "_shrubbery in the working" 
  << " directory and writes ASCII trees inside it.---"
  << std::endl;
}
