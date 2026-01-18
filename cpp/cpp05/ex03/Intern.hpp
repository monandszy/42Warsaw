#ifndef INTERN_HPP
#define INTERN_HPP

class AForm;

#include <iostream>

class Intern {
 private:
  AForm* presidential(const std::string& target);
  AForm* robotomy(const std::string& target);
  AForm* shrubbery(const std::string& target);

  struct Entry {
    const char* key;
    AForm* (Intern::*value)(const std::string& target);
  };

 public:
  Intern();
  ~Intern();
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  AForm* makeForm(const std::string& key, const std::string& target);
};

#endif