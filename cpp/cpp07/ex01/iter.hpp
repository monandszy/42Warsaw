#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T a[], const int len, void (*apply)(const T&)) {
  for (int i = 0; i < len; i++) apply(a[i]);
}

template <typename T>
void apply(const T& obj) {
  std::cout << "applying to: " << obj << std::endl;
}

#endif