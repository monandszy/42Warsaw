#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int sign_grade, int exec_grade)
    : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
  if (sign_grade > 150)
    throw InvalidExpertiseException(
        "InvalidExpertiseException: sign_grade input");
  else if (sign_grade < 1)
    throw InvalidExpertiseException(
        "InvalidExpertiseException: sign_grade input");
  if (exec_grade > 150)
    throw InvalidExpertiseException(
        "InvalidExpertiseException: exec_grade input");
  else if (exec_grade < 1)
    throw InvalidExpertiseException(
        "InvalidExpertiseException: exec_grade input");
  this->_signed = false;
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
  if (this != &other) {
    this->_signed = other._signed;
  }
  return *this;
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _sign_grade(other._sign_grade),
      _exec_grade(other._exec_grade) {
  this->_signed = other._signed;
}

const std::string& AForm::getName() const { return _name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getSignGrade() const { return _sign_grade; }

int AForm::getExecGrade() const { return _exec_grade; }

void AForm::beSigned(Bureaucrat& slave) {
  if (slave.getGrade() <= _sign_grade)
    _signed = true;
  else
    throw InvalidExpertiseException("InvalidExpertiseException: " + _name);
}

std::ostream& operator<<(std::ostream& os, const AForm& other) {
  os << other.getName() << "[";
  os << "signed=" << other.getSigned();
  os << " sign_grade=" << other.getSignGrade();
  os << " exec_grade=" << other.getExecGrade();
  os << "]";
  return os;
}

AForm::InvalidExpertiseException::InvalidExpertiseException(
    const std::string& message) throw()
    : std::invalid_argument(message) {}

AForm::InvalidExpertiseException::~InvalidExpertiseException() throw() {}

AForm::FormNotSignedException::FormNotSignedException(
    const std::string& message) throw()
    : std::invalid_argument(message) {}

AForm::FormNotSignedException::~FormNotSignedException() throw() {}
