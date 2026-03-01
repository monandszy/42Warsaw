#ifndef BTC_HHP
#define BTC_HPP

/*
Parse data file
Parse input file

multimap
*/

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

void log(const std::string& s);

static bool isnum(const char* str) {
  double result;
  std::istringstream i(str);
  i >> result;
  return !i.fail() && i.eof();
}

// https://stackoverflow.com/questions/9436697/c-check-if-a-date-is-valid
static bool isdate(const char* str) {
  struct tm tm;
  if (!strptime(str, "%Y-%m-%d", &tm)) return (false);
  return (true);
}

template <typename T>
void parse_ssv(T& csv, std::ifstream& in, const std::string& s) {
  for (std::string line; getline(in, line);) {
    if (line.find(s) == std::string::npos) {
      log("ERROR: while looking for csv separator");
      continue;
    }
    int spos = line.find(s);
    std::string key = line.substr(0, spos);
    std::string value = line.substr(spos + s.size());

    if (!(isdate(key.c_str()) && isnum(value.c_str()))) {
      log("ERROR: while validating key and value");
      continue;
    }
    std::stringstream sd(value);
    double v;
    sd >> v;
    if (v < 0) {
      log("ERROR: negative value");
      continue;
    }
    csv.insert(std::make_pair(key, v));
  }
}

template <typename T>
void parse_file(T& csv, const std::string& name, const std::string& s) {
  std::ifstream in(name.c_str());

  if (!in.is_open()) {
    log("ERROR: while opening file");
  }
  std::string f;
  getline(in, f);
  parse_ssv(csv, in, s);
  in.close();
}

#endif