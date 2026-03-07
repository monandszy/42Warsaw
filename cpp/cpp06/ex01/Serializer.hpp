#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // for uintptr_t

class Data;

class Serializer {
 private:
  Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif