#ifndef INSERTION_HPP
#define INSERTION_HPP

#include <algorithm>
#include <cmath>
#include <utility>

// bound = initial position of paired in main chain
template <typename T, typename U>
void initialize_tofrom(int argc, int pow, T& t, T& to, U& from) {
  typename T::iterator it = t.begin();

  int pairc = (argc / pow);
  int c = pow * pairc;
  int group_num = 0;
  for (int i = 0; i < c; i++) {
    if (it == t.end()) break;
    if (i < pow * 2) {
      to.push_back(*it);
    } else if ((i / pow) % 2 == 0) {
      int bound = group_num + 2;
      from.push_back(std::make_pair(*it, bound));
      if ((i + 1) % pow == 0) group_num++;
    } else {
      to.push_back(*it);
    }
    ++it;
  }
}

int get_Jacobsthal(int prev, int curr);

template <typename T>
void replace_to(int argc, int pow, T& to, T& from) {
  typename T::iterator ti = to.begin();
  typename T::iterator fi = from.begin();

  int pairc = (argc / pow);
  int c = pow * pairc;
  for (int i = 0; i < c; i++) {
    if (ti == to.end() || fi == from.end()) {
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

template <typename T, typename Ui>
void insert_group_from_pairs(T& to, typename T::iterator insert_pos_it,
                             Ui group_start_it, int pow) {
  T values;
  Ui pair_it = group_start_it;
  for (int p = 0; p < pow; ++p) {
    values.push_back(pair_it->first);
    ++pair_it;
  }
  to.insert(insert_pos_it, values.begin(), values.end());
}

template <typename T>
T find_insertion_point(T range_begin, int num_groups, int pow, int target,
                       int& out_idx) {
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

  out_idx = low;
  T insertion_point = range_begin;
  std::advance(insertion_point, low * pow);
  return insertion_point;
}

template <typename U>
void update_bounds(U& from, int insert_idx) {
  for (typename U::iterator it = from.begin(); it != from.end(); ++it) {
    if (it->second >= insert_idx) {
      it->second++;
    }
  }
}

template <typename T, typename U>
void process_Jacobsthal_set(T& to, U& from, typename U::iterator& target_begin,
                            typename U::iterator& target, int pow, int count) {
  while (count > 0) {
    int to_insert = target->first;
    int bound_i = target->second;

    int to_size = static_cast<int>(to.size() / pow);
    if (bound_i > to_size) bound_i = to_size;

    int insert_idx = 0;
    typename T::iterator begin = to.begin();
    typename T::iterator point =
        find_insertion_point(begin, bound_i, pow, to_insert, insert_idx);

    insert_group_from_pairs(to, point, target_begin, pow);

    update_bounds(from, insert_idx);

    reverse(target, from.begin(), pow);
    reverse(target_begin, from.begin(), pow);
    count--;
  }
}

template <typename T, typename U>
void optimal_binary_insert(T& to, U& from, int pow) {
  int from_size = static_cast<int>(from.size()) / pow;
  int prev_j = 1;
  int curr_j = 3;

  while (1) {
    int limit_c = std::min(curr_j - 1, from_size);
    int j_c = limit_c - prev_j;

    typename U::iterator target_begin = from.begin();
    forward(target_begin, from.end(), (limit_c - 1) * pow);

    typename U::iterator target = target_begin;
    forward(target, from.end(), pow - 1);

    int count = j_c + 1;
    process_Jacobsthal_set(to, from, target_begin, target, pow, count);

    if (from_size < curr_j) break;
    int next_j = get_Jacobsthal(prev_j, curr_j);
    prev_j = curr_j;
    curr_j = next_j;
  }
}

#endif