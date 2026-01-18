#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& slave) const {
  if (!this->getSigned()) throw FormNotSignedException(slave.getName().c_str());
  if (slave.getGrade() > this->getExecGrade())
    throw InvalidExpertiseException(slave.getName().c_str());
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
