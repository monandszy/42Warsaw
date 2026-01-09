#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, Form& other) {
  os << other.getName() << "[";
  os << "signed=" << other.getSigned();
  os << " sign_grade=" << other.getSignGrade();
  os << " exec_grade=" << other.getExecGrade();
  os << "]";
  return os;
}

std::string Form::getName()
{
  return _name;
}

float Form::getSigned() {
  return _signed;
}

int Form::getSignGrade() {
  return _sign_grade;
}

int Form::getExecGrade() {
  return _exec_grade;
}

Form::~Form() {
}

Form::Form(const std::string name, int sign_grade, int exec_grade) 
: _name(name),
  _sign_grade(sign_grade),
  _exec_grade(exec_grade)
{
  if (sign_grade > 150)
    throw GradeTooHighException("sign_grade");
  else if (sign_grade < 1)
    throw GradeTooLowException("sign_grade");
  if (exec_grade > 150)
    throw GradeTooHighException("exec_grade");
  else if (exec_grade < 1)
    throw GradeTooLowException("exec_grade");
  this->_signed = false;
}

Form::Form(const Form& other) 
: _name(other._name),
  _sign_grade(other._sign_grade),
  _exec_grade(other._exec_grade) 
{
  this->_signed = other._signed;
}

Form& Form::operator=(const Form& other) {
  return (Form&) other;
}

void Form::beSigned(Bureaucrat& slave) {
  if (slave.getGrade() <= _sign_grade)
    _signed = true;
  else
    throw GradeTooLowException(_name.c_str());
}