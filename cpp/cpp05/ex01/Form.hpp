#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool _signed;
  const int _sign_grade;
  const int _exec_grade;
  Form();

 public:
  Form(const std::string& name, int sign_grade, int exec_grade);
  ~Form();
  Form& operator=(const Form& other);
  Form(const Form& other);

  const std::string& getName() const;
  bool getSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(Bureaucrat& slave);

  class InvalidExpertiseException : public std::invalid_argument {
   public:
    InvalidExpertiseException(const std::string& message) throw();
    virtual ~InvalidExpertiseException() throw();
  };
};
std::ostream& operator<<(std::ostream& os, const Form& obj);
#endif