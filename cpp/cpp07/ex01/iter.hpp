template <typename T>
void iter(T a[], const int len, void (*apply)(T&)) {
  for (int i = 0; i < len; i++) apply(a[i]);
}

template <typename T>
void apply(T& obj) {
  std::cout << "appling to: " << obj << std::endl;
}