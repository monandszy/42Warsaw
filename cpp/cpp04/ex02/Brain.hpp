#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include "Brain.hpp"

class Brain {
  protected:
    std::string _ideas[100];
  public:
    Brain(void) = default;
    ~Brain(void) = default;
    Brain& operator=(const Brain& other) = default;
    Brain(const Brain& other) = default;
};
#endif