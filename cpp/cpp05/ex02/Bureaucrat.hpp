#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

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

  void signForm(AForm& target);
  void executeForm(AForm const& form) const;

  class GradeTooHighException : public std::runtime_error {
   public:
    GradeTooHighException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~GradeTooHighException() throw(){};
  };

  class GradeTooLowException : public std::runtime_error {
   public:
    GradeTooLowException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~GradeTooLowException() throw(){};
  };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif
