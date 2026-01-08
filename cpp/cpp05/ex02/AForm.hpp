#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureucrat;

class Form  
{
  private:
    const std::string _name;
    bool _signed;
    const int _sign_grade;
    const int _exec_grade;
  public:
    virtual ~Form();
    virtual Form& operator=(const Form& other);
    Form(const std::string name, int sign_grade, int exec_grade);
    Form(const Form& other);

    std::string getName() const;
    float getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    virtual void beSigned(Bureucrat& slave);
    virtual void execute(const Bureucrat& slave) const = 0;

};
std::ostream& operator<<(std::ostream& os, Form& obj);
#endif