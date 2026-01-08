#include "Bureucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main(void)
{
  Bureucrat b1("b1", 1);
  Bureucrat b2("b2", 150);
  ShrubberyCreationForm sf1;
  Form &f1 = sf1;
  std::cout << f1 << std::endl;
  // ShrubberyCreationForm f2();
  
  try
  {
    b1.executeForm(f1);
    b1.signForm(f1);
    b1.executeForm(f1);
    // b2.signForm(f2);
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
}