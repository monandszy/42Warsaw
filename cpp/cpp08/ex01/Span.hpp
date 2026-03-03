#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

class Span {
 private:
  Span();
  unsigned int _N;
  unsigned int _index;
  std::set<unsigned int> _mem;

 public:
  ~Span();
  Span(unsigned int);
  Span(const Span& other);
  Span& operator=(const Span& other);
  void addNumber(unsigned int i);
  void addNumber(unsigned int start, unsigned int end);
  unsigned int shortestSpan();
  unsigned int longestSpan();
};
#endif