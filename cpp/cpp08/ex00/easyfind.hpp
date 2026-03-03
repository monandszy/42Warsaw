#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int& easyfind(T& hay, int needle) {
  try {
    for (typename T::iterator it = hay.begin(); it != hay.end(); ++it) {
      if (*it == needle) return *it;
    }
  } catch (std::exception& e) {
    throw std::out_of_range("Not Found");
  }
  throw std::out_of_range("Not Found");
}

#endif