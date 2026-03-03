/*
Ford-Johnson algorithm
Merge insertion sort.

Output:
Unsorted
Sorted
Time C1
Time C2
*/
// std::list
// std::vector

#include <algorithm>
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
  std::cout << "Sorted: ";
  std::cout << "[";
  for (typename T::iterator it = t.begin(); it != t.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << " ]" << std::endl;
}

// double sort(int argc, std::vector<int> v) {

// }

int main(int argc, char* argv[]) {
  if (argc == 1) {
    log("ERROR: invalid argument count");
    return 1;
  }

  std::vector<int> v;
  v.reserve(argc - 1);
  std::list<int> l;

  try {
    initialize(argc, argv, v);
    initialize(argc, argv, l);
    print_argv(argc, argv);
    std::sort(v.begin(), v.end());
    l.sort();
    print_sorted(v);
    print_sorted(l);
    // print_sorted(l);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}