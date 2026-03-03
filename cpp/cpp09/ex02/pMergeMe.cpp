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

#include "pMergeMe.hpp"

template <typename T>
void move(T& it, const T& end, int c) {
  for (int i = 0; i < c; i++) {
    if (it == end) break;
    ++it;
  }
}

// if (t.size() == 2) {
//   typename T::iterator first = t.begin();
//   typename T::iterator second = first++;
//   if (*first < *second) {
//     int tmp;
//     tmp = *first;
//     *first = *second;
//     *second = tmp;
//   }
//   return;
// }

template <typename T>
void order_pairs(int pow, T& t) {
  typename T::iterator it = t.begin();
  typename T::iterator curr_pair_begin = it;
  typename T::iterator next_pair_begin;
  move(it, t.end(), pow - 1);

  while (it != t.end()) {
    typename T::iterator curr = it;
    move(it, t.end(), 1);
    next_pair_begin = it;
    move(it, t.end(), pow - 1);
    typename T::iterator next = it;
    if (next != t.end()) {
      // std::cout << "[" << *curr_pair_begin << "|" << *curr << "|"
      //           << *next_pair_begin << "|" << *next << "]" << std::endl;
      if (*curr > *next) {
        while (1) {
          int tmp = *curr_pair_begin;
          *curr_pair_begin = *next_pair_begin;
          *next_pair_begin = tmp;
          if (curr_pair_begin == curr) break;
          ++curr_pair_begin;
          ++next_pair_begin;
        }
      }
    } else {
      break;
    }
    // print_sorted(t);
    // std::cout << "a[" << *curr_pair_begin << "|" << *curr << "|"
    //           << *next_pair_begin << "|" << *next << "]" << std::endl;
    move(it, t.end(), 1);
    curr_pair_begin = it;
    move(it, t.end(), pow - 1);
  }
}

// pair as <small, big>
template <typename T>
void sort(int argc, int pow, T& t) {
  if (pow * 2 > argc) return;

  order_pairs(pow, t);
  sort(argc, pow * 2, t);
  print_sorted(t);

  T main;
  T pend;

  typename T::iterator it = t.begin();

  int pairc = (argc / pow);
  int c = pow * pairc;
  std::cout << c << "|" << pairc << "|" << pow << std::endl;
  for (int i = 0; i < c; i++) {
    if (it == t.end()) break;
    if (i < pow * 2)
      main.push_back(*it);
    else if ((i / pow) % 2 == 0)
      pend.push_back(*it);
    else
      main.push_back(*it);
    ++it;
  }
  std::cout << "main: ";
  print_sorted(main);
  std::cout << "pend: ";
  print_sorted(pend);
}

// merge insertion sort

// divide into pairs of 2.
// sort each pair.
// combine pairs using binary insertion utill all combined

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
    // sort(v);
    sort(argc, 1, l);
    // std::sort(v.begin(), v.end());
    // l.sort();
    // print_sorted(v);
    print_sorted(l);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}