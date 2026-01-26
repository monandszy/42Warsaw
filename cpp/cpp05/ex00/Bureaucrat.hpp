#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;
  Bureaucrat();

 public:
  ~Bureaucrat();
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);

  std::string getName() const;
  int getGrade() const;

  void promote();
  void punish();

  class GradeTooHighException : public std::invalid_argument {
   public:
    GradeTooHighException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~GradeTooHighException() throw(){};
  };

  class GradeTooLowException : public std::invalid_argument {
   public:
    GradeTooLowException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~GradeTooLowException() throw(){};
  };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif
