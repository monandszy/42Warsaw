#ifndef IMPL_HPP
#define IMPL_HPP

#include "Base.hpp"

class A : public Base {
 public:
  A();
  ~A();
  A(const A& other);
  const A& operator=(const A& other);
};

class B : public Base {
 public:
  B();
  ~B();
  B(const B& other);
  const B& operator=(const B& other);
};

class C : public Base {
 public:
  C();
  ~C();
  C(const C& other);
  const C& operator=(const C& other);
};

#endif