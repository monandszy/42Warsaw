#include "Data.hpp"

Data::Data() {}

Data::~Data() {}

const Data Data::operator=(const Data& other) {
  if (this != &other) {
    this->_data = other._data;
  }
  return (*this);
}

Data::Data(const Data& other) { this->_data = other._data; }

Data::Data(std::string data) { _data = data; }

std::string& Data::get_data() { return _data; }
