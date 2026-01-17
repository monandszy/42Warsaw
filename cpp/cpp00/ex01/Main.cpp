
#include "Contact.hpp"
#include "Phonebook.hpp"

// int main(int argc, char *argv[])

void add(Phonebook& phonebook) {
  static int order = 1;

  std::string number;
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string darkestSecret;

  std::cout << "Number: ";
  std::cin >> number;
  std::cout << "FirstName: ";
  std::cin >> firstName;
  std::cout << "LastName: ";
  std::cin >> lastName;
  std::cout << "Nickname: ";
  std::cin >> nickname;
  std::cout << "DarkestSecret: ";
  std::cin >> darkestSecret;

  Contact contact(order, number, firstName, lastName, nickname, darkestSecret);
  phonebook.add(contact);
  order++;
}

void print_details(Phonebook& phonebook, int index) {
  Contact contact = phonebook.getContact(index);
  std::cout << "Number: " << contact.getNumber() << std::endl;
  std::cout << "FirstName: " << contact.getFirstName() << std::endl;
  std::cout << "LastName: " << contact.getLastName() << std::endl;
  std::cout << "Nickname: " << contact.getNickname() << std::endl;
  std::cout << "DarkestSecret: " << contact.getDarkestSecret() << std::endl;
}

void search(Phonebook& phonebook) {
  phonebook.print();
  std::cout << "Index:";
  int in;
  while (!(std::cin >> in) || in < 0 || in > 7) {
    std::cin.clear();
    std::cout << "Invalid input." << std::endl;
    std::cout << "Index:";
  }
  print_details(phonebook, in);
}

int main(void) {
  Phonebook phonebook;

  std::string input = "";

  while (input != "END") {
    if (input == "ADD")
      add(phonebook);
    else if (input == "SEARCH")
      search(phonebook);
    std::cin >> input;
  }
  return (0);
}