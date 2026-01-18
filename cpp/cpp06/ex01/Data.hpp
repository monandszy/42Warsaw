#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
 private:
  std::string _data;

 public:
  Data();
  ~Data();
  const Data operator=(const Data& other);
  Data(const Data& other);
  Data(std::string data);
  std::string& get_data();
};

#endif