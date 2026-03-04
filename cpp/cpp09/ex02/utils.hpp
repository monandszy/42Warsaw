#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

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

#endif