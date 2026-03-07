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

#include <climits>
#include <ctime>
#include <iomanip>

#include "init.hpp"
#include "insertion.hpp"
#include "ordering.hpp"
#include "sorting.hpp"
#include "utils.hpp"

int get_Jacobsthal(int prev, int curr) { return (prev + 2 * curr); }

void print_argv(int argc, char* argv[]) {
  std::cout << "Unsorted: ";
  std::cout << "[";
  for (int i = 1; i < argc; i++) {
    std::cout << " " << argv[i];
  }
  std::cout << " ]" << std::endl;
}

void log(const std::string& s) { std::cout << "[" << s << "]" << std::endl; }

bool isnum(const char* str) {
  if (str == NULL || *str == '\0') return false;
  if (*str == '-') return false;
  for (const char* p = str; *p; ++p) {
    if (!isdigit(*p)) return false;
  }
  return true;
}

// std::sort(v.begin(), v.end());
// l.sort();
int main(int argc, char* argv[]) {
  if (argc == 1) {
    log("ERROR: invalid argument count");
    return 1;
  }

  std::vector<int> v;
  std::list<int> l;

  try {
    initialize(argc, argv, v);
    initialize(argc, argv, l);
    print_argv(argc, argv);

    std::clock_t start_v = std::clock();
    sort<std::vector<int>, std::vector<std::pair<int, int> > >(argc - 1, 1, v);
    std::clock_t stop_v = std::clock();

    double duration_v = double(stop_v - start_v) / CLOCKS_PER_SEC;
    std::cout << "vector: " << std::fixed << std::setprecision(6) << duration_v
              << " seconds" << std::endl;
    print_sorted(v);
    is_sorted(v);

    std::clock_t start_l = std::clock();  // time start
    sort<std::list<int>, std::list<std::pair<int, int> > >(argc - 1, 1, l);
    std::clock_t stop_l = std::clock();  // time stop

    double duration_l = double(stop_l - start_l) / CLOCKS_PER_SEC;
    std::cout << "list: " << std::fixed << std::setprecision(6) << duration_l
              << " seconds" << std::endl;

    print_sorted(l);
    is_sorted(l);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}