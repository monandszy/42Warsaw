#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int& easyfind(T& hay, int needle) {
  for (typename T::iterator it = hay.begin(); it != hay.end(); ++it) {
    if (*it == needle) return *it;
  }
  throw std::out_of_range("Not Found");
}

#endif