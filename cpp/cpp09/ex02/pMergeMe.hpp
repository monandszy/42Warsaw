#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

void log(const std::string& s) { std::cout << "[" << s << "]" << std::endl; }

static bool isnum(const char* str) {
  double result;
  std::istringstream i(str);
  i >> result;
  return !i.fail() && i.eof();
}

template <typename T>
void initialize(int argc, char* argv[], T& c) {
  for (int i = 1; i < argc; i++) {
    if (!isnum(argv[i])) {
      throw std::runtime_error("ERROR: argument not a number");
    }
    int a;
    std::stringstream si(argv[i]);
    si >> a;
    if (a < 0) {
      throw std::runtime_error("ERROR: argument negative");
    }
    c.push_back(a);
  }
}

void print_argv(int argc, char* argv[]) {
  std::cout << "Unsorted: ";
  std::cout << "[";
  for (int i = 1; i < argc; i++) {
    std::cout << " " << argv[i];
  }
  std::cout << " ]" << std::endl;
}

template <typename T>
void print_sorted(T& t) {
  std::cout << "[";
  for (typename T::iterator it = t.begin(); it != t.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << " ]" << std::endl;
}

#endif