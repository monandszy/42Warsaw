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
void forward(T& it, const T& end, int c) {
  for (int i = 0; i < c; i++) {
    if (it == end) break;
    ++it;
  }
}

template <typename T>
void reverse(T& it, const T& begin, int c) {
  for (int i = 0; i < c; i++) {
    if (it == begin) break;
    --it;
  }
}

template <typename T>
void order_pairs(int pow, T& t) {
  typename T::iterator it = t.begin();
  typename T::iterator curr_pair_begin = it;
  typename T::iterator next_pair_begin;
  forward(it, t.end(), pow - 1);

  while (it != t.end()) {
    typename T::iterator curr = it;
    forward(it, t.end(), 1);
    next_pair_begin = it;
    forward(it, t.end(), pow - 1);
    typename T::iterator next = it;
    if (next != t.end()) {
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
    forward(it, t.end(), 1);
    curr_pair_begin = it;
    forward(it, t.end(), pow - 1);
  }
}

template <typename T>
void initialize_tofrom(int argc, int pow, T& t, T& to, T& from) {
  typename T::iterator it = t.begin();

  int pairc = (argc / pow);
  int c = pow * pairc;
  for (int i = 0; i < c; i++) {
    if (it == t.end()) break;
    if (i < pow * 2)
      to.push_back(*it);
    else if ((i / pow) % 2 == 0)
      from.push_back(*it);
    else
      to.push_back(*it);
    ++it;
  }
}

template <typename T>
void replace_to(int argc, int pow, T& to, T& from) {
  typename T::iterator ti = to.begin();
  typename T::iterator fi = from.begin();

  int pairc = (argc / pow);
  int c = pow * pairc;
  std::cout << "cccccccccccc:" << c << std::endl;
  for (int i = 0; i < c; i++) {
    if (ti == to.end() || fi == from.end()) {
      std::cout << "!!!!!!!!!!!!!!!!!!!!!" << std::endl;
      break;
    }
    *ti = *fi;
    ++ti;
    ++fi;
  }
}

template <typename T>
void insert_group(T& to, typename T::iterator insert_pos_it,
                  typename T::iterator group_start_it, int pow) {
  typename T::iterator end = group_start_it;
  forward(end, to.end(), pow);
  to.insert(insert_pos_it, group_start_it, end);
}

template <typename T>
T find_insertion_point(T range_begin, int num_groups, int pow, int target) {
  int low = 0;
  int high = num_groups;

  while (low < high) {
    int mid_group_idx = low + (high - low) / 2;
    T mid_group_start = range_begin;
    std::advance(mid_group_start, mid_group_idx * pow);

    T key_iterator = mid_group_start;
    std::advance(key_iterator, pow - 1);
    if (*key_iterator < target) {
      low = mid_group_idx + 1;
    } else {
      high = mid_group_idx;
    }
  }

  T insertion_point = range_begin;
  std::advance(insertion_point, low * pow);
  return insertion_point;
}

int get_Jacobsthal(int prev, int curr) { return (prev + 2 * curr); }

// pair as <small, big>
// Jn​=Jn−1​+2Jn−2
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
    std::cout << "prefrom: ";
    print_sorted(from);
    std::cout << "preto: ";
    print_sorted(to);
    int from_size = from.size() / pow;
    int prev_j = 1;
    int curr_j = 3;
    while (1) {
      int limit_c = std::min(curr_j - 1, from_size);
      int j_i = limit_c - prev_j;

      typename T::iterator target_begin = from.begin();
      forward(target_begin, from.end(), (limit_c - 1) * pow);

      std::cout << "shift: " << j_i << std::endl;
      typename T::iterator target = target_begin;
      forward(target, from.end(), pow - 1);

      int count = j_i + 1;
      while (count > 0) {
        std::cout << "pair:" << *target_begin << "|" << *target << std::endl;
        int to_insert = *target;
        // I need to find the bound (ax) to limit the insertion and optimize the binary search.
        int bound_i = curr_j;

        std::cout << "bound_i: " << bound_i << std::endl;
        typename T::iterator begin = to.begin();
        typename T::iterator point =
            find_insertion_point(begin, bound_i, pow, to_insert);

        insert_group(to, point, target_begin, pow);
        std::cout << "from: ";
        print_sorted(from);
        std::cout << "to: ";
        print_sorted(to);

        reverse(target, to.begin(), pow);
        reverse(target_begin, to.begin(), pow);
        count--;
      }
      std::cout << "-------------" << std::endl;
      if (from_size < curr_j) break;
      int next_j = get_Jacobsthal(prev_j, curr_j);
      prev_j = curr_j;
      curr_j = next_j;
    }
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