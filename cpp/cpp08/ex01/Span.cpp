#include "Span.hpp"

#include <stdexcept>
#include <cstdarg>

Span::~Span() { delete[] _mem; }

Span::Span() {
  _size = 0;
  _memsize = 10;
  _mem = new int[_memsize];
}

Span::Span(unsigned int i) {
  _size = 0;
  _memsize = 10;
  _mem = new int[_memsize];
  addNumber(i);
}

Span::Span(const Span& other) {
  this->_mem = new int[other._memsize];
  for (unsigned int i = 0; i < _memsize; i++) {
    this->_mem[i] = other._mem[i];
  }
  this->_size = other._size;
  this->_memsize = other._memsize;
}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    delete[] this->_mem;
    this->_mem = new int[other._memsize];
    for (unsigned int i = 0; i < _memsize; i++) {
      this->_mem[i] = other._mem[i];
    }
    this->_size = other._size;
    this->_memsize = other._memsize;
  }
  return *this;
}

void Span::addNumber(unsigned int i) {
  
}

void Span::addNumber(unsigned int start, unsigned int end) {

}

unsigned int Span::shortestSpan() {
  if (_size < 2) throw std::out_of_range("Span not found");
  return 0;
}

unsigned int Span::longestSpan() {
  if (_size < 2) throw std::out_of_range("Span not found");
  return 0;
}
