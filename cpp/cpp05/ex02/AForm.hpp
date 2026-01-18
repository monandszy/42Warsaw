#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
 private:
  const std::string _name;
  bool _signed;
  const int _sign_grade;
  const int _exec_grade;

 public:
  virtual ~AForm();
  virtual AForm& operator=(const AForm& other);
  AForm(const std::string name, int sign_grade, int exec_grade);
  AForm(const AForm& other);

  std::string getName() const;
  bool getSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  virtual void beSigned(Bureaucrat& slave);
  virtual void execute(const Bureaucrat& slave) const = 0;

  class FormNotSignedException : public std::runtime_error {
   public:
    FormNotSignedException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~FormNotSignedException() throw(){};
  };
  class InvalidExpertiseException : public std::runtime_error {
   public:
    InvalidExpertiseException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~InvalidExpertiseException() throw(){};
  };
};
std::ostream& operator<<(std::ostream& os, const AForm& obj);
#endif