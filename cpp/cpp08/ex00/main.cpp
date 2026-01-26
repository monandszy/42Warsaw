#include <iostream>

#include "Array.hpp"
#include "easyfind.hpp"

int main(void) {
  Array<int> a(4);

  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 4;

  std::cout << easyfind(a, 1) << std::endl;
  std::cout << easyfind(a, 2) << std::endl;
  std::cout << easyfind(a, 3) << std::endl;

  try {
    std::cout << easyfind("cat", 3) << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::cout << easyfind(a, -1000) << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}