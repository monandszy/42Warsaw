#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <stack>
#include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T>  > {
 public:
  class iterator {
   private:
    typename std::deque<T>::iterator _it;
    iterator();

   public:
    ~iterator() {}
    iterator(typename std::deque<T>::iterator it) { _it = it; }
    iterator(const iterator& other) { *this = other; }
    iterator& operator=(const iterator& other) {
      if (this != &other) {
        this->_it = other._it;
      }
      return *this;
    }
    T& operator*() const { return *_it; }
    iterator& operator++() {
      ++_it;
      return *this;
    }
    iterator operator++(int) {
      iterator tmp = *this;
      ++_it;
      return tmp;
    }
    iterator& operator--() {
      --_it;
      return *this;
    }
    iterator operator--(int) {
      iterator tmp = *this;
      --_it;
      return tmp;
    }
    bool operator==(const iterator& other) { return this->_it == other._it; }
    bool operator!=(const iterator& other) { return this->_it != other._it; }
  };

  ~MutantStack() {}
  MutantStack() : std::stack<T, std::deque<T> >() {}
  MutantStack(const MutantStack<T>& other)
      : std::stack<T, std::deque<T> >(other) {
    *this = other;
  }
  MutantStack<T>& operator=(const MutantStack<T>& other) {
    if (this != &other) {
      std::stack<T>::operator=(other);
    }
    *this;
  }
  typename MutantStack<T>::iterator begin() {
    return iterator(this->c.begin());
  }
  typename MutantStack<T>::iterator end() { return iterator(this->c.end()); }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& other) {
  os << "{";
  for (typename MutantStack<T>::iterator it = other.begin(); it != other.end();
       ++it) {
    os << "[" << *it << "]";
  }
  os << "}";
  return os;
}
#endif