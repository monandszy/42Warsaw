#include "Impl.hpp"

  A::A() : Base() {}

  A::~A() {}

  A::A(const A& other) : Base() {(void) other;}

  const A& A::operator=(const A& other) {
    (void) other;
    return *this;
  }


  B::B() : Base() {}

  B::~B() {}

  B::B(const B& other) : Base() {(void) other;}

  const B& B::operator=(const B& other) {
    (void) other;
    return *this;
  }


  C::C() : Base() {}

  C::~C() {}

  C::C(const C& other) : Base() {(void) other;}

  const C& C::operator=(const C& other) {
    (void) other;
    return *this;
  }
