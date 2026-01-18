#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Intern i;
  AForm* f1;
  AForm* f2;
  AForm* f3;

  try {
    f1 = i.makeForm("presidential pardon", "Alice");
    f2 = i.makeForm("robotomy request", "Bender");
    f3 = i.makeForm("shrubbery creation", "home");

    if (f1 && f2 && f3) {
      Bureaucrat b1("b1", 1);

      std::cout << *f1 << std::endl;
      b1.signForm(*f1);
      b1.executeForm(*f1);

      std::cout << *f2 << std::endl;
      b1.signForm(*f2);
      b1.executeForm(*f2);

      std::cout << *f3 << std::endl;
      b1.signForm(*f3);
      b1.executeForm(*f3);
    }

    delete f1;
    delete f2;
    delete f3;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}