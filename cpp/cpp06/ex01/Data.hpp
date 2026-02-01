#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
 private:
  std::string _data;

 public:
  Data();
  Data(const std::string& data);
  ~Data();
  const Data operator=(const Data& other);
  Data(const Data& other);

  const std::string& getData();
};

#endif