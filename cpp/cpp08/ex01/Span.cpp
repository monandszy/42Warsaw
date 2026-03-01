#include "Span.hpp"

#include <algorithm>
#include <climits>
#include <cstdarg>
#include <stdexcept>

Span::~Span() {}

Span::Span(unsigned int N) {
  _N = N;
  _mem.reserve(N);
  _index = 0;
}

Span::Span(const Span& other) { *this = other; }

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    this->_mem = other._mem;
    this->_N = other._N;
    this->_index = other._index;
  }
  return *this;
}

void Span::addNumber(unsigned int i) {
  if (_index == _N) throw std::out_of_range("Index out of range");
  for (std::vector<unsigned int>::iterator it = _mem.begin(); it != _mem.end();
       ++it) {
    if (*it == i) throw std::invalid_argument("Number already exists");
  }
  _mem.push_back(i);
  _index++;
}

// append_range in cpp++23
void Span::addNumber(unsigned int start, unsigned int end) {
  if (end < start) std::invalid_argument("Invalid Span");
  std::sort(_mem.begin(), _mem.end());
  for (std::vector<unsigned int>::iterator it = _mem.begin(); it != _mem.end();
       ++it) {
    if (*it >= start) {
      if (*(it) <= end)
        throw std::invalid_argument("Number already exists");
      else
        break;
    }
  }
  if (_index + (end - start) > _N)
    throw std::out_of_range("Index out of range");
  for (unsigned int i = start; i <= end; ++i) {
    _mem.push_back(i);
  }
}

unsigned int Span::shortestSpan() {
  if (_index < 2) throw std::out_of_range("Span not found");
  std::sort(_mem.begin(), _mem.end());
  int min = INT_MAX;
  int prev = _mem.at(0);
  for (std::vector<unsigned int>::iterator it = ++_mem.begin();
       it != _mem.end(); ++it) {
    int dist = *it - prev;
    if (dist < min) min = dist;
    prev = *it;
  }
  return min;
}

unsigned int Span::longestSpan() {
  if (_index < 2) throw std::out_of_range("Span not found");
  std::sort(_mem.begin(), _mem.end());
  unsigned int max = *std::max_element(_mem.begin(), _mem.end());
  unsigned int min = *std::min_element(_mem.begin(), _mem.end());
  return (max - min);
}
