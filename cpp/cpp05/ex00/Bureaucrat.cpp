
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
  if (grade > 150)
    throw GradeTooLowException("GradeTooLowException: " + _name);
  else if (grade < 1)
    throw GradeTooHighException("GradeTooHighException: " + _name);
  _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    this->_grade = other._grade;
  }
  return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
  *this = other;
}

void Bureaucrat::promote() {
  if (_grade == 1)
    throw GradeTooHighException("GradeTooHighException: " + _name);
  _grade--;
}

void Bureaucrat::punish() {
  if (_grade == 150)
    throw GradeTooLowException("GradeTooLowException: " + _name);
  _grade++;
}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other) {
  os << other.getName() << ", bureaucrat grade " << other.getGrade();
  return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string& message)
    : std::invalid_argument(message) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    const std::string& message)
    : std::invalid_argument(message) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}