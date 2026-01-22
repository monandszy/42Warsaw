#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool _signed;
  const int _sign_grade;
  const int _exec_grade;
  Form();

 public:
  ~Form();
  Form(const std::string name, int sign_grade, int exec_grade);
  Form(const Form& other);
  Form& operator=(const Form& other);

  std::string getName() const;
  bool getSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(Bureaucrat& slave);

  class InvalidExpertiseException : public std::runtime_error {
   public:
    InvalidExpertiseException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~InvalidExpertiseException() throw() {};
  };
};
std::ostream& operator<<(std::ostream& os, const Form& obj);
#endif