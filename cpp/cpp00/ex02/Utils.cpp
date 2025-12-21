#include "Utils.hpp"
#include <ctime>
#include <iostream>

/* https://stackoverflow.com/questions/997946/how-can-i-get-current-time-and-date-in-c 

1992 01 04 _ 09 15 32
*/
void printCurrentDateTime()
{
  time_t t = std::time(0);
  std::tm now = *std::localtime(&t);
  char buf[80];
  strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", &now);
  std::cout << buf;
}