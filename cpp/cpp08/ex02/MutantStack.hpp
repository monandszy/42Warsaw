#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <stdexcept>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T> {
 private:
  typename std::vector<T> _m;

 public:
  class iterator {
   private:
    typename std::vector<T>::iterator _it;
    iterator();

   public:
    ~iterator() {}
    iterator(typename std::vector<T>::iterator it) { _it = it; }
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
  MutantStack() {}
  MutantStack(const MutantStack<T>& other) { *this = other; }
  MutantStack<T>& operator=(const MutantStack<T>& other) {
    if (this != &other) {
      this->_m = other._m;
    }
    *this;
  }
  MutantStack<T>::iterator begin() { return iterator(_m.begin()); }
  MutantStack<T>::iterator end() { return iterator(_m.end()); }
  void push(T t) { _m.push_back(t); }
  void pop() { _m.pop_back(); }
  T& top() { return *_m.end(); }
  size_t size() { return _m.size(); }
  bool empty() { return _m.empty(); }
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