#ifndef BTC_HPP
#define BTC_HPP

/*
Parse data file
Parse input file

multimap
*/

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>

void log(const std::string& s);

bool isnum(const char* str);
// https://stackoverflow.com/questions/9436697/c-check-if-a-date-is-valid
bool isdate(const char* str);

template <typename T>
void parse_ssv(T& csv, std::ifstream& in, const std::string& s,
               int (*validate)(double, int)) {
  int i = 0;
  for (std::string line; getline(in, line);) {
    i++;
    if (line.find(s) == std::string::npos) {
      std::cout << "ERROR[" << i << "] while looking for csv separator"
                << std::endl;
      continue;
    }
    int spos = line.find(s);
    std::string key = line.substr(0, spos);
    std::string value = line.substr(spos + s.size());

    if (!(isdate(key.c_str()) && isnum(value.c_str()))) {
      std::cout << "ERROR[" << i << "] while validating key and value"
                << std::endl;
      continue;
    }
    std::stringstream sd(value);
    double v;
    sd >> v;

    if ((*validate)(v, i)) continue;
    csv.insert(std::make_pair(key, v));
  }
}

#endif