#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
 private:
  const std::string _name;
  bool _signed;
  const int _sign_grade;
  const int _exec_grade;
  AForm();

 public:
  AForm(const std::string& name, int sign_grade, int exec_grade);
  virtual ~AForm();
  AForm& operator=(const AForm& other);
  AForm(const AForm& other);

  const std::string& getName() const;
  bool getSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  virtual void beSigned(Bureaucrat& slave);
  virtual void execute(const Bureaucrat& slave) const = 0;

  class InvalidExpertiseException : public std::invalid_argument {
   public:
    InvalidExpertiseException(const std::string& message) throw();
    virtual ~InvalidExpertiseException() throw();
  };

  class FormNotSignedException : public std::invalid_argument {
   public:
    FormNotSignedException(const std::string& message) throw();
    virtual ~FormNotSignedException() throw();
  };
};
std::ostream& operator<<(std::ostream& os, const AForm& obj);
#endif