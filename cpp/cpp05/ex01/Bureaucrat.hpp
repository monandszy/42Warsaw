#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;
  Bureaucrat();

 public:
  Bureaucrat(const std::string& name, int grade);
  ~Bureaucrat();
  Bureaucrat& operator=(const Bureaucrat& other);
  Bureaucrat(const Bureaucrat& other);

  void promote();
  void punish();

  const std::string& getName() const;
  int getGrade() const;
  void signForm(Form& target);

  class GradeTooHighException : public std::invalid_argument {
   public:
    GradeTooHighException(const std::string& message);
    virtual ~GradeTooHighException() throw();
  };

  class GradeTooLowException : public std::invalid_argument {
   public:
    GradeTooLowException(const std::string& message);
    virtual ~GradeTooLowException() throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif
