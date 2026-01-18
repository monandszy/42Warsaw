
#include "Bureaucrat.hpp"

#include "Form.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other) {
  os << other.getName() << ">, bureaucrat grade " << other.getGrade();
  return os;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::promote() {
  if (_grade == 1) throw GradeTooHighException(_name.c_str());
  _grade--;
}

void Bureaucrat::punish() {
  if (_grade == 150) throw GradeTooLowException(_name.c_str());
  _grade++;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  if (grade > 150)
    throw GradeTooLowException(name.c_str());
  else if (grade < 1)
    throw GradeTooHighException(name.c_str());
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
  this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    this->_grade = other._grade;
  }
  return *this;
}

void Bureaucrat::signForm(Form& target) {
  try {
    target.beSigned(*this);
    std::cout << _name << " signed " << target.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << _name << " couldn't sign " << target.getName()
              << " because: " << e.what() << std::endl;
  }
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    char const* const message) throw()
    : std::runtime_error(message) {}

char const* Bureaucrat::GradeTooHighException::what() const throw() {
  return "GradeTooHigh";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    char const* const message) throw()
    : std::runtime_error(message) {}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
  return "GradeTooLow";
}