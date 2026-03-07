#ifndef INIT_HPP
#define INIT_HPP

#include <climits>

#include "utils.hpp"

void log(const std::string& s);

bool isnum(const char* str);

template <typename T>
void initialize(int argc, char* argv[], T& c) {
  for (int i = 1; i < argc; i++) {
    if (!isnum(argv[i])) {
      throw std::runtime_error("ERROR: argument not a positive integer");
    }
    long long a;
    std::stringstream si(argv[i]);
    si >> a;
    if (a > INT_MAX) {
      throw std::runtime_error("ERROR: integer overflow");
    }
    c.push_back(static_cast<int>(a));
  }
}

void print_argv(int argc, char* argv[]);

template <typename T>
void print_sorted(T& t) {
  std::cout << "[";
  for (typename T::iterator it = t.begin(); it != t.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << " ]" << std::endl;
}

#endif