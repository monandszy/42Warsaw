#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat b1("b1", 150);
  ShrubberyCreationForm sf1("home");
  AForm &f1 = sf1;

  std::cout << f1 << std::endl;
  RobotomyRequestForm rf2("Bender");
  AForm &f2 = rf2;
  std::cout << f2 << std::endl;

  PresidentialPardonForm pf3("Arthur Dent");
  AForm &f3 = pf3;
  std::cout << f3 << std::endl;

  try {
    b1.executeForm(f1);
    std::cout << std::endl;
    b1.signForm(f1);
    b1.executeForm(f1);
    std::cout << std::endl;
    b1.signForm(f2);
    b1.executeForm(f2);
    std::cout << std::endl;
    b1.signForm(f3);
    b1.executeForm(f3);

    // b2.executeForm(f1);
    // std::cout << std::endl;
    // b2.signForm(f1);
    // b2.executeForm(f1);
    // std::cout << std::endl;
    // b2.signForm(f2);
    // b2.executeForm(f2);
    // std::cout << std::endl;
    // b2.signForm(f3);
    // b2.executeForm(f3);

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}