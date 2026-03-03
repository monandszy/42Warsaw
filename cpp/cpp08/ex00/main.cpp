#include <iostream>

#include <vector>
#include "easyfind.hpp"

int main(void) {
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);

  std::cout << easyfind(a, 1) << std::endl;
  std::cout << easyfind(a, 2) << std::endl;
  std::cout << easyfind(a, 3) << std::endl;

  // try {
  //   std::cout << easyfind("cat", 3) << std::endl;
  // } catch (std::exception& e) {
  //   std::cerr << e.what() << std::endl;
  // }

  try {
    std::cout << easyfind(a, -1000) << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}