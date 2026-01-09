#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
  Bureaucrat b1("b1", 1);
  Bureaucrat b2("b2", 150);
  Form f1("f1", 20, 20);
  std::cout << f1 << std::endl;
  Form f2("f1", 20, 20);
  
  try
  {
    b1.signForm(f1);
    b2.signForm(f2);
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
}