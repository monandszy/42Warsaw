#include "Harl.hpp"

int main(void) {
  Harl harl;

  harl.complain("invalid");
  std::cout << std::endl;
  harl.complain("debug");
  std::cout << std::endl;
  harl.complain("info");
  std::cout << std::endl;
  harl.complain("warning");
  std::cout << std::endl;
  harl.complain("error");
}