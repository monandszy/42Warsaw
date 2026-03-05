#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();

 public:
  static void convert(const std::string& input);
};

#endif
