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

#include "init.hpp"
#include "insertion.hpp"
#include "ordering.hpp"
#include "utils.hpp"

template <typename T>
void sort(int argc, int pow, T& t) {
  if (pow * 2 > argc) return;

  order_pairs(pow, t);
  sort(argc, pow * 2, t);
  print_sorted(t);

  T to;
  T from;
  initialize_tofrom(argc, pow, t, to, from);
  std::cout << "pow: " << pow << std::endl;

  if (from.size() != 0) {
    optimal_binary_insert(to, from, pow);
    replace_to(argc, pow, t, to);
    std::cout << std::endl;
  }
}

// std::sort(v.begin(), v.end());
// l.sort();
int main(int argc, char* argv[]) {
  if (argc == 1) {
    log("ERROR: invalid argument count");
    return 1;
  }

  std::vector<int> v;
  // v.reserve(argc - 1);
  std::list<int> l;

  try {
    initialize(argc, argv, v);
    initialize(argc, argv, l);
    print_argv(argc, argv);
    sort(argc - 1, 1, v);
    // sort(argc, 1, l);
    print_sorted(v);
    // print_sorted(l);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}