#include "Base.hpp"
#include "Impl.hpp"

int main(void)
{
  for (int i = 0; i < 10; i++)
  {
    Base *b = Base::generate();
    Base& bb = *b;
    Base::identify(bb);
    delete b;
  }
}