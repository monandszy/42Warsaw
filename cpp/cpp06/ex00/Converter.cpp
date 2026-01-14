#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

static bool isnum(const char *str)
{
  double result;
  std::istringstream i(str);

  i >> result;      

  return !i.fail() && i.eof();
}

static void print_table(
  std::string c,
  std::string i,
  std::string f,
  std::string d
){
  std::cout
  << "char: " << c << std::endl 
  << "int: " << i << std::endl 
  << "float: " << f << std::endl 
  << "double: " << d << std::endl;
}

static void convert(char *str)
{
  std::string cppstr = str;

  // validate double infinity
  if (cppstr == "-inf" || cppstr == "+inf" || cppstr == "nan")
  {
    print_table("impossible", "impossible", cppstr + "f", cppstr);
  }
  // validate float
  else if (cppstr.length() != 1 && str[cppstr.length() - 1] == 'f')
  {
    if (cppstr == "-inf" || cppstr == "+inf" || cppstr == "nan")
    {
      print_table("impossible", "impossible", cppstr, cppstr);
      return ;
    }
    std::string cut = cppstr.substr(0, cppstr.length()-1);

    if (isnum((cut.c_str())))
    {
      std::cout << "Data type Float" << std::endl;
      float f;
      std::stringstream sf(cut);
      sf >> f;

      std::stringstream res;
      res << std::setprecision(9) << f;

      double d;
      d = f;
      std::stringstream sd;
      sd << std::setprecision(9) << d;

      int i;
      i = d;
      std::stringstream si;
      si << std::setprecision(9) << i;

      char c;
      c = f;
      std::stringstream sc;
      sc << std::setprecision(9) << c;

      print_table("'" + sc.str() + "'", si.str(), res.str() + "f", sd.str());
      return ;
    }
    else
    {
      std::cout << "Invalid float input" << std::endl;
    }
  }
  else if (isnum(str))
  {
    // validate double
    if (cppstr.find(".") != std::string::npos)
    {
      std::cout << "Data type Double" << std::endl;
      double d;
      std::stringstream sd(str);
      sd >> d;

      std::stringstream res;
      res << std::setprecision(17) << d;

      float f;
      f = d;
      std::stringstream sf;
      sf << std::setprecision(17) << f;

      int i;
      i = d;
      std::stringstream si;
      si << std::setprecision(17) << i;

      char c;
      c = d;
      std::stringstream sc;
      sc << std::setprecision(17) << c;

      print_table("'" + sc.str() + "'", si.str(), sf.str() + "f", res.str());
    }
    // validate int
    else
    {
      std::cout << "Data type Int" << std::endl;
      int i;
      std::stringstream si(str);
      si >> i;

      std::stringstream res;
      res << i;

      float f;
      f = i;
      std::stringstream sf;
      sf << f;

      double d;
      d = i;
      std::stringstream sd;
      sd << d;

      char c;
      c = i;
      std::stringstream sc;
      sc << c;

      print_table("'" + sc.str() + "'", res.str(), sf.str() + "f", sd.str());
    }
  }
  else if (cppstr.length() == 1)
  {
    std::cout << "Data type Char" << std::endl;
    char c;
    c = str[0];

    int i;
    i = c;
    std::stringstream si;
    si << i;

    float f;
    f = i;
    std::stringstream sf;
    sf << f;

    double d;
    d = i;
    std::stringstream sd;
    sd << d;

    print_table("'" + cppstr + "'", si.str(), sf.str() + "f", sd.str());
  }
  else
  {
    std::cout << "Data type not recoginized, possibly a string or null" << std::endl;
    return ;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Invalid argument count" << std::endl;
    return (1);
  } 
  convert(argv[1]);
  return (0);
}