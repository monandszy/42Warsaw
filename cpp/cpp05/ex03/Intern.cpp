#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return (*this);
}

AForm* Intern::presidential(const std::string& target) {
  return new PresidentialPardonForm(target);
}

AForm* Intern::robotomy(const std::string& target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::shrubbery(const std::string& target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& key, const std::string& target) {
  static Entry table[] = {{"presidential pardon", &Intern::presidential},
                          {"robotomy request", &Intern::robotomy},
                          {"shrubbery creation", &Intern::shrubbery},
                          {NULL, NULL}};

  int i = 0;

  while (table[i].key) {
    if (std::string(table[i].key) == key) {
      std::cout << "Intern creates " << key << std::endl;
      return (this->*table[i].value)(target);
    }
    i++;
  }
  std::cout << "Intern cannot create " << key << " because it doesn't exist"
            << std::endl;
  return NULL;
}
