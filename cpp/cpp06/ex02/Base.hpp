#ifndef BASE_HPP
#define BASE_HPP

class Base
{
  public:
    Base();
    virtual ~Base();
    Base(const Base& other);
    const Base& operator=(const Base& other);

    static Base * generate(void);
    static void identify(Base* p);
    static void identify(Base& p);
};

#endif