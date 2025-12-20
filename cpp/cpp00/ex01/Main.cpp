
#include "Phonebook.hpp"
#include "Contact.hpp"

// int main(int argc, char *argv[])

void add()
{
  // static int order = 1;
}

void search()
{

}

int main(void)
{
  Contact contact;
  Phonebook phonebook;

  std::string input = "";
  
  while(input != "END")
  {
    std::cin>>input;
    if (input == "ADD")
      add();
    if (input == "SEARCH")
      search();
  }
  return (0);
}