#ifndef WHATEVER_TTP
#define WHATEVER_TTP

template <typename T>
static void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
static T& min(T& a, T& b) {
  if (a > b) return (b);
  return (a);
}

template <typename T>
static T& max(T& a, T& b) {
  if (a < b) return (b);
  return (a);
}

#endif