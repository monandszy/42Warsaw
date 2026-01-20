#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int easyfind(T& hay, int needle) {
  for (int i = 0; hay[i]; i++) {
    if (hay[i] == needle) return i;
  }
  throw std::runtime_error("Not Found");
}

#endif