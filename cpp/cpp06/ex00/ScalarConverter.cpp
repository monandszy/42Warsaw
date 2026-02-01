#include "ScalarConverter.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

static bool isnum(const char* str) {
  double result;
  std::istringstream i(str);

  i >> result;

  return !i.fail() && i.eof();
}

static std::string getc(char c) {
  if (std::isprint(c)) {
    std::stringstream sc;
    sc << c;
    return ("'" + sc.str() + "'");
  } else
    return ("Not printable");
}

static void print_table(std::string c, std::string i, std::string f,
                        std::string d) {
  std::cout << "char: " << c << std::endl
            << "int: " << i << std::endl
            << "float: " << f << std::endl
            << "double: " << d << std::endl;
}

static void print_values(char c, int i, float f, double d) {
  std::stringstream si;
  si << i;
  std::stringstream sf;
  sf << std::fixed << f;
  std::stringstream sd;
  sd << std::fixed << d;
  print_table(getc(c), si.str(), sf.str() + "f", sd.str());
}

void ScalarConverter::convert(char* str) {
  std::string cppstr = str;

  // validate double infinity
  if (cppstr == "-inf" || cppstr == "+inf" || cppstr == "nan") {
    std::cout << "Data type Escape" << std::endl;
    print_table("impossible", "impossible", cppstr + "f", cppstr);
  }
  // validate float
  else if (cppstr.length() != 1 && str[cppstr.length() - 1] == 'f') {
    if (cppstr == "-inff" || cppstr == "+inff" || cppstr == "nanf") {
      std::cout << "Data type Escape" << std::endl;
      print_table("impossible", "impossible", cppstr,
                  cppstr.substr(0, cppstr.length() - 1));
      return;
    }
    std::string cut = cppstr.substr(0, cppstr.length() - 1);

    if (isnum((cut.c_str()))) {
      std::cout << "Data type Float" << std::endl;
      float f;
      std::stringstream sf(cut);
      sf >> f;
      print_values(static_cast<char>(f), static_cast<int>(f), f,
                   static_cast<double>(f));
    } else {
      std::cout << "Invalid float input" << std::endl;
    }
  } else if (isnum(str)) {
    // validate double
    if (cppstr.find(".") != std::string::npos) {
      std::cout << "Data type Double" << std::endl;
      double d;
      std::stringstream sd(str);
      sd >> d;
      print_values(static_cast<char>(d), static_cast<int>(d),
                   static_cast<float>(d), d);
    }
    // validate int (no . detected)
    else {
      std::cout << "Data type Int" << std::endl;
      int i;
      std::stringstream si(str);
      si >> i;
      print_values(static_cast<char>(i), i, static_cast<float>(i),
                   static_cast<double>(i));
    }
  } else if (cppstr.length() == 1) {
    std::cout << "Data type Char" << std::endl;
    char c;
    c = str[0];
    print_values(c, static_cast<int>(c), static_cast<float>(c),
                 static_cast<double>(c));
  } else {
    std::cout << "Data type not recoginized, possibly a string or null or an "
                 "out of scope double"
              << std::endl;
    return;
  }
}