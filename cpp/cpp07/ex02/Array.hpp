#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
 private:
  unsigned int _size;
  T* _arr;

 public:
  ~Array() { delete[] _arr; }

  Array() {
    _size = 0;
    _arr = new T[0];
  }

  Array(unsigned int size) {
    _size = size;
    _arr = new T[size];
  }

  Array(const Array<T>& other) {
    this->_arr = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++) {
      this->_arr[i] = other._arr[i];
    }
  }

  Array<T>& operator=(const Array<T>& other) {
    if (this != &other) {
      delete[] this->_arr;
      this->_arr = new T[other._size];
      for (unsigned int i = 0; i < other._size; i++) {
        this->_arr[i] = other._arr[i];
      }
    }
    return *this;
  }

  T& operator[](unsigned int index) {
    if (index >= _size) {
      throw std::invalid_argument("Invalid Index");
    }
    return _arr[index];
  }

  unsigned int size() { return _size; }
};
#endif