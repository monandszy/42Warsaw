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

#include <ctime>
#include <iomanip>

#include "init.hpp"
#include "insertion.hpp"
#include "ordering.hpp"
#include "utils.hpp"

template <typename T>
void is_sorted(T& t) {
  int prev = *t.begin();
  for (typename T::iterator it = ++t.begin(); it != t.end(); ++it) {
    if (prev > *it) {
      log("!!!!!!!!!!!!!!!!!Not Sorted!!!!!!!!!!!!!!!");
      std::cout << prev << "|" << *it << std::endl;
    }
    prev = *it;
  }
}

template <typename T, typename U>
void sort(int argc, int pow, T& t) {
  if (pow * 2 > argc) return;

  order_pairs(pow, t);
  sort<T, U>(argc, pow * 2, t);
  // print_sorted(t);

  T to;
  U from;  // U is container of pairs (value, bound)
  initialize_tofrom(argc, pow, t, to, from);
  // std::cout << "pow: " << pow << std::endl;

  if (from.size() != 0) {
    optimal_binary_insert(to, from, pow);
    replace_to(argc, pow, t, to);
    // std::cout << std::endl;
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