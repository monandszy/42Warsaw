#ifndef ORDERING_HPP
#define ORDERING_HPP

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

#endif