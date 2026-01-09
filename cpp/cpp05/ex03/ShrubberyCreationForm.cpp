#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <sstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
  : Form("ShrubberyCreationForm", 145, 137) 
{}

void ShrubberyCreationForm::execute(const Bureaucrat& slave) const {
  if (!this->getSigned())
    throw FormNotSignedException(slave.getName().c_str());
  if (!(slave.getGrade() <= this->getExecGrade()))
    throw GradeTooLowException(this->getName().c_str());
  std::cout << "---" << slave.getName() 
  << " Creates a file " << this->getName() 
  << "_shrubbery in the working" 
  << " directory and writes ASCII trees inside it.---"
  << std::endl;
  std::ofstream outFile((this->getName() + "_replaced").c_str());
  if (!outFile.is_open())
  {
    std::cout << "Could not open output file" << std::endl;
    return ;
  }
  outFile << " \
\n\
      / \\   / \\   / \\   / \\   / \\  \n \
     \\|/   \\|/   \\|/   \\|/   \\|/  \n \
______|_____|_____|_____|_____|____    \n\
  ";
  outFile.close();
}
