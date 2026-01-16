#include "Base.hpp"
#include "Impl.hpp"
#include <cstdlib>
#include <iostream>

Base::Base() {}

Base::~Base() {}

Base::Base(const Base& other) {
  (void) other;
}

const Base& Base::operator=(const Base& other) {
  (void) other;
  return *this;
}

Base* Base::generate(void) {
 int rand = std::rand() % 3;
 if (rand == 0)
 {
    A *a = new A;
    std::cout << &a << " A Generated" << std::endl;
    return (a);
 }
 else if (rand == 1)
 {
    B *b = new B;
    std::cout << &b << " B Generated" << std::endl;
    return (b);
 }
 else
 {
    C *c = new C;
    std::cout << &c << " C Generated" << std::endl;
    return (c);
 }
}

void Base::identify(Base* p) {
  
  if (dynamic_cast<A *>(p))
    std::cout << p << " A Detected" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << p << " B Detected" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << p << " C Detected" << std::endl;
  else
    std::cout << "Unknown type" << std::endl;
}

void Base::identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    (void) a;
    std::cout << &p << " A Detected" << std::endl;
  } catch (std::exception &e) {
    try {
      B& b = dynamic_cast<B&>(p);
      (void) b;
      std::cout << &p << " B Detected" << std::endl;
    } catch (std::exception &e) {
      try {
        C& c = dynamic_cast<C&>(p);
        (void) c;
        std::cout << &p << " C Detected" << std::endl;
      } catch (std::exception &e) {
        std::cout << "Unknown type" << std::endl;
      }
    }
  }
}

