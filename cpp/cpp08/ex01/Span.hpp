#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
 private:
  unsigned int _size;
  unsigned int _memsize;
  int* _mem;

 public:
  ~Span();
  Span();
  Span(unsigned int);
  Span(const Span& other);
  Span& operator=(const Span& other);
  void addNumber(unsigned int i);
  void addNumber(unsigned int start, unsigned int end);
  unsigned int shortestSpan();
  unsigned int longestSpan();
};
#endif