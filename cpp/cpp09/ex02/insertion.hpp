#ifndef INSERTION_HPP
#define INSERTION_HPP

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

int get_Jacobsthal(int prev, int curr) { return (prev + 2 * curr); }

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

template <typename T>
void process_Jacobsthal_set(T& to, T& from, typename T::iterator& target_begin,
                            typename T::iterator& target, int pow, int curr_j,
                            int count) {
  while (count > 0) {
    // std::cout << "pair:" << *target_begin << "|" << *target << std::endl;
    int to_insert = *target;
    // I need to find the bound (ax) to limit the insertion and optimize the
    // binary search.
    int bound_i = curr_j;  // <------------- wrong

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
}

template <typename T>
void optimal_binary_insert(T& to, T& from, int pow) {
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

    process_Jacobsthal_set(to, from, target_begin, target, pow, curr_j,
                           j_i + 1);

    std::cout << "-------------" << std::endl;
    if (from_size < curr_j) break;
    int next_j = get_Jacobsthal(prev_j, curr_j);
    prev_j = curr_j;
    curr_j = next_j;
  }
}

#endif