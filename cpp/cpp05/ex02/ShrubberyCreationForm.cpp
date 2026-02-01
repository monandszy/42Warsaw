#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <sstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

void ShrubberyCreationForm::execute(const Bureaucrat& slave) const {
  if (!this->getSigned())
    throw FormNotSignedException("FormNotSignedException: " + slave.getName());
  if (slave.getGrade() > this->getExecGrade())
    throw InvalidExpertiseException("InvalidExpertiseException: " +
                                    slave.getName());

  std::ofstream outFile((_target + "_shrubbery").c_str());
  if (!outFile.is_open()) {
    std::cout << "Could not open output file" << std::endl;
    return;
  }
  outFile << " \
\n\
      / \\   / \\   / \\   / \\   / \\  \n \
     \\|/   \\|/   \\|/   \\|/   \\|/  \n \
______|_____|_____|_____|_____|____    \n\
  ";
  outFile.close();
}
