#include <iostream>

#include "iter.hpp"

int main(void) {
  int arr[20];
  for (int i = 0; i < 20; i++) arr[i] = 20 + i;
  iter(arr, 20, &apply);
  for (int i = 0; i < 20; i++) std::cout << "post: " << arr[i] << std::endl;
  iter(arr, 20, &print);
}