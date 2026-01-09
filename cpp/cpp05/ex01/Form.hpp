#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form  
{
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

    std::string getName();
    float getSigned();
    int getSignGrade();
    int getExecGrade();

    void beSigned(Bureaucrat& slave);

};
std::ostream& operator<<(std::ostream& os, Form& obj);
#endif