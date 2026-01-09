#include "Bureaucrat.hpp"

int main(void)
{
  Bureaucrat b1("b1", 1);
  std::cout << b1 << std::endl;
  // b1.promote();
  // Bureaucrat b2("b2", -2);
  // Bureaucrat b3("b3", 160);

  // Bureaucrat b4("b3", 150);
  // b4.punish();
  
  try
  {
    Bureaucrat b10("b10", 1);
    Bureaucrat b11("b11", -2);
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
}