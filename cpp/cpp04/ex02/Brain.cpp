#include "Brain.hpp"

Brain::Brain(void) {
  for (int i = 0; i < 100; i++) {
    this->_ideas[i] = "Idea: " + i;
  }
}

Brain::~Brain(void) {}

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (int i = 0; i < 100; i++) {
      this->_ideas[i] = other._ideas[i];
    }
  }
  return *this;
}

Brain::Brain(const Brain& other) {
  for (int i = 0; i < 100; i++) {
    this->_ideas[i] = other._ideas[i];
  }
}
