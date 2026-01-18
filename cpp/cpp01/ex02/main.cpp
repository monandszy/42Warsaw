#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";

  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "str: " << &str << std::endl;
  std::cout << "strPTR: " << stringPTR << std::endl;
  std::cout << "strREF: " << &stringREF << std::endl;

  std::cout << "str: " << str << std::endl;
  std::cout << "strPTR: " << *stringPTR << std::endl;
  std::cout << "strREF: " << stringREF << std::endl;
}