#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
  Intern i;
  
  try
  { 
    Form& f1 = i.makeForm("presidential");
    Form& f2 = i.makeForm("robotomy");
    Form& f3 = i.makeForm("shrubbery");
    Bureaucrat b1("b1", 1);

    b1.signForm(f1);
    b1.signForm(f2);
    b1.signForm(f3);

    delete &f1;
    delete &f2;
    delete &f3;
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
}