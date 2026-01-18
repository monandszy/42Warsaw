
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <limits>
#include <sstream>

// int main(int argc, char *argv[])

void add(Phonebook& phonebook) {
  static int order = 1;

  std::string number;
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string darkestSecret;

  std::cout << "Number: ";
  std::getline(std::cin, number);
  std::cout << "FirstName: ";
  std::getline(std::cin, firstName);
  std::cout << "LastName: ";
  std::getline(std::cin, lastName);
  std::cout << "Nickname: ";
  std::getline(std::cin, nickname);
  std::cout << "DarkestSecret: ";
  std::getline(std::cin, darkestSecret);

  Contact contact(order, number, firstName, lastName, nickname, darkestSecret);
  phonebook.add(contact);
  order++;
}

void search(Phonebook& phonebook) {
  int in;
  std::string input;

  while (true) {
    std::cout << "Index> ";
    if (!std::getline(std::cin, input)) {
      if (std::cin.eof()) break;
    }
    std::stringstream ss(input);
    if (ss >> in && in >= 0 && in <= 7) {
        break; 
    }
    std::cout << "Invalid input." << std::endl;
  }

  Contact contact = phonebook.getContact(in);
  std::cout << "Number: " << contact.getNumber() << std::endl;
  std::cout << "FirstName: " << contact.getFirstName() << std::endl;
  std::cout << "LastName: " << contact.getLastName() << std::endl;
  std::cout << "Nickname: " << contact.getNickname() << std::endl;
  std::cout << "DarkestSecret: " << contact.getDarkestSecret() << std::endl;
}

int main(void) {
  Phonebook phonebook;

  std::string input = "";
  std::cout << "> ";
  while (std::getline(std::cin, input) && input != "END") {
    if (input.empty()) {
    }
    else if (input == "ADD") {
      add(phonebook);
    } else if (input == "SEARCH") {
      phonebook.print();
      search(phonebook);
    } else {
      std::cout << "Unknown command" << std::endl;
    }
    std::cout << "> ";
  }
  return (0);
}