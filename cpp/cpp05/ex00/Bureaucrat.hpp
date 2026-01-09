#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
  private:
    const std::string _name;
    int _grade;
    Bureaucrat();
  public:
    ~Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    std::string getName();
    int getGrade();

    void promote();
    void punish();
};

class GradeTooHighException : public std::runtime_error
{
  private:
    std::string _msg;
  public:
    GradeTooHighException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~GradeTooHighException() throw() {}; 
};

class GradeTooLowException : public std::runtime_error
{
  private:
    std::string _msg;
  public:
    GradeTooLowException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~GradeTooLowException() throw() {}; 
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);
#endif
