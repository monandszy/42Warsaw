#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int easyfind(T& hay, int needle) {
  try {
    for (int i = 0; hay[i]; i++) {
      if (hay[i] == needle) return i;
    }
  } catch (std::exception& e) {
    throw std::out_of_range("Not Found");
  }
  throw std::out_of_range("Not Found");
}

#endif