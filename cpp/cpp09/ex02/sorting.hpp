#ifndef SORTING_HPP
#define SORTING_HPP

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
  U from;
  initialize_tofrom(argc, pow, t, to, from);
  // std::cout << "pow: " << pow << std::endl;

  if (from.size() != 0) {
    optimal_binary_insert(to, from, pow);
    replace_to(argc, pow, t, to);
    // std::cout << std::endl;
  }
}

#endif