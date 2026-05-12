#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T a[], const int len, F f) {
  for (int i = 0; i < len; i++) apply(a[i]);
}

template <typename T>
void apply(T& obj) {
  std::cout << "applying to: " << obj << std::endl;
  obj += obj;
}

template <typename T>
void print(const T& obj) {
  std::cout << "printing: " << obj << std::endl;
}

#endif