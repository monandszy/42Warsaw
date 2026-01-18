#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

  struct Entry {
    const char* key;
    void (Harl::*value)();
  };

 public:
  void complain(std::string level);
  Harl(void);
  ~Harl(void);
  Harl& operator=(const Harl& other);
  Harl(const Harl& other);
};

#endif