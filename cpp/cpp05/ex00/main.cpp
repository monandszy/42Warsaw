#include "Bureucrat.hpp"

int main(void)
{
  Bureucrat b1("b1", 1);
  std::cout << b1 << std::endl;
  // b1.promote();
  // Bureucrat b2("b2", -2);
  // Bureucrat b3("b3", 160);

  // Bureucrat b4("b3", 150);
  // b4.punish();
  
  try
  {
    Bureucrat b10("b10", 1);
    Bureucrat b11("b11", -2);
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
}