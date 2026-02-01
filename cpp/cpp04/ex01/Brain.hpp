#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>

class Brain {
 protected:
  std::string _ideas[100];

 public:
  Brain(void);
  ~Brain(void);
  Brain& operator=(const Brain& other);
  Brain(const Brain& other);
};

#endif