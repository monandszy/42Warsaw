#include <iostream>

// void printUpper(std::string s)
// {
//   std::transform(s.begin(), s.end(), s.begin(), ::toupper);
//   std::cout << s;
// }

int main(int argc, char *argv[]) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      std::string s = argv[i];
      for (std::size_t j = 0; j < s.length(); j++) s[j] = toupper(s[j]);
      std::cout << s;
    }
    std::cout << std::endl;
  } else {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }
  return (0);
}