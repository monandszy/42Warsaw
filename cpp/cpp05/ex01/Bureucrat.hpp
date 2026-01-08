#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>

class Form;

class Bureucrat
{
  private:
    const std::string _name;
    int _grade;
    Bureucrat();
  public:
    ~Bureucrat();
    Bureucrat(const std::string name, int grade);
    Bureucrat(const Bureucrat& other);
    Bureucrat& operator=(const Bureucrat& other);

    std::string getName();
    int getGrade();

    void promote();
    void punish();

    void signForm(Form& target);
};

class GradeTooHighException : public std::runtime_error
{
  public:
    GradeTooHighException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~GradeTooHighException() throw() {}; 
};

class GradeTooLowException : public std::runtime_error
{
  public:
    GradeTooLowException(char const* const message) throw();
    virtual char const* what() const throw();
    virtual ~GradeTooLowException() throw() {}; 
};

std::ostream& operator<<(std::ostream& os, Bureucrat& obj);
#endif
