#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << "Brain constructor called" << std::endl;
  for (int i = 0; i < 100; i++) {
    this->_ideas[i] = "Idea: " + i;
  }
}

Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (int i = 0; i < 100; i++) {
      this->_ideas[i] = other._ideas[i];
    }
  }
  return *this;
}

Brain::Brain(const Brain& other) { *this = other; }
