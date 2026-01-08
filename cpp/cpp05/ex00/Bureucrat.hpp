#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>

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

std::ostream& operator<<(std::ostream& os, Bureucrat& obj);
#endif
