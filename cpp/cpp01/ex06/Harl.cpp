#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

Harl& Harl::operator=(const Harl& other) {
  (void)other;
  return *this;
}

Harl::Harl(const Harl& other) { *this = other; }

void Harl::complain(std::string level) {
  int numeric_level = -1;

  static Entry table[] = {
      {"debug", 3}, {"info", 2}, {"warning", 1}, {"error", 0}, {NULL, 0}};

  int i = 0;
  while (table[i].key) {
    if (std::string(table[i].key) == level) {
      numeric_level = table[i].level;
      break;
    }
    i++;
  }

  switch (numeric_level) {
    case 3:
      debug();
      // fall through
    case 2:
      info();
      // fall through
    case 1:
      warning();
      // fall through
    case 0:
      error();
      break;
    default:
      std::cout << "Shh.." << std::endl;
  }
}

void Harl::debug(void) {
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning(void) {
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years, whereas you started working here just last month."
      << std::endl;
}

void Harl::error(void) {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}