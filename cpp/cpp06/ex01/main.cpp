#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
  Data* d = new Data("cat");

  std::cout << d->getData() << std::endl;
  uintptr_t t = Serializer::serialize(d);
  std::cout << t << std::endl;
  Data* td = Serializer::deserialize(t);
  std::cout << td->getData() << std::endl;

  delete d;
}