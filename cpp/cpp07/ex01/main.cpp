#include <iostream>

template<typename T>
void iter(T a[], const int len, void (*apply)(T&)) {
  for(int i = 0; i < len; i++)
    apply(a[i]);
}

template<typename T>
void apply(T& obj) {
  std::cout << "appling to: " << obj << std::endl;
}

int main(void)
{
  int arr[20];
  for (int i = 0; i < 20; i++)
    arr[i] = 20 + i;
  iter(arr, 20, &apply);
  for (int i = 0; i < 20; i++)
    std::cout << "post: " << arr[i] << std::endl;

  const int arc[5] = {1, 2, 3, 4, 5};
  iter(arc, 5, &apply);
  for (int i = 0; i < 5; i++)
    std::cout << "post: " << arc[i] << std::endl;

  std::string ars[20];
  for (int i = 0; i < 20; i++)
    ars[i] = "happy string";
  iter(ars, 20, &apply);
  for (int i = 0; i < 20; i++)
    std::cout << "post: " << ars[i] << std::endl;
}