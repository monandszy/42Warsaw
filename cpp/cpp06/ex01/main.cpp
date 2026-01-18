#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
  Data* d = new Data("cat");

  std::cout << d->get_data() << std::endl;
  uintptr_t t = Serializer::serialize(d);
  std::cout << t << std::endl;
  Data* td = Serializer::deserialize(t);
  std::cout << td->get_data() << std::endl;

  delete d;
}