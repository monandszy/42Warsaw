#include "Data.hpp"

Data::Data() {}

Data::Data(const std::string& data) { _data = data; }

Data::~Data() {}

const Data Data::operator=(const Data& other) {
  if (this != &other) {
    this->_data = other._data;
  }
  return (*this);
}

Data::Data(const Data& other) { *this = other; }

const std::string& Data::getData() { return _data; }
