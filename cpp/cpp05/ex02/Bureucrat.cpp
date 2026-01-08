
#include "Bureucrat.hpp"
#include "AForm.hpp"

std::ostream& operator<<(std::ostream& os, Bureucrat& other) {
  os << other.getName() << ">, bureaucrat grade " << other.getGrade();
  return os;
}

std::string Bureucrat::getName() const {
  return _name;
}

int Bureucrat::getGrade() const {
  return _grade;
}

void Bureucrat::promote() {
  if (_grade == 1)
    throw GradeTooHighException(_name.c_str());
  _grade--;
}

void Bureucrat::punish() {
  if (_grade == 150)
    throw GradeTooLowException(_name.c_str());
  _grade++;
}

Bureucrat::~Bureucrat() {
}

Bureucrat::Bureucrat(const std::string name, int grade) : _name(name) {
  if (grade > 150) 
    throw GradeTooHighException(name.c_str());
  else if (grade < 1)
    throw GradeTooLowException(name.c_str());
  _grade = grade;
}

Bureucrat::Bureucrat(const Bureucrat& other) : _name(other._name) {
  this->_grade = other._grade;
}

Bureucrat& Bureucrat::operator=(const Bureucrat& other) {
  return (Bureucrat&) other;
}

GradeTooHighException::GradeTooHighException(char const* const message) throw()
  : std::runtime_error(message)
{
}

char const * GradeTooHighException::what() const throw()
{
  return "GradeTooHigh";
}

GradeTooLowException::GradeTooLowException(char const* const message) throw()
  : std::runtime_error(message)
{
}

char const * GradeTooLowException::what() const throw()
{
  return "GradeTooLow";
}

FormNotSignedException::FormNotSignedException(char const* const message) throw()
  : std::runtime_error(message)
{
}

char const * FormNotSignedException::what() const throw()
{
  return "FormNotSigned";
}

void Bureucrat::signForm(Form& target)
{
  try {
    target.beSigned(*this); 
    std::cout << _name << " signed " << target.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << _name << " couldn't sign " << target.getName() << " because: " << e.what() << std::endl;
  }
}

void Bureucrat::executeForm(Form const & target) const {
  try {
    target.execute(*this);
    std::cout << _name << " executed " << target.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << _name << " couldn't execute " << target.getName() << " because: " << e.what() << std::endl;
  }
}