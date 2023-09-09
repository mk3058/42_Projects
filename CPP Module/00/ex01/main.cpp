#include "Contact.hpp"
#include "Phonebook.hpp"

std::string getInput(std::string str) {
  std::string input;

  do {
    if (!str.empty()) std::cout << str;
    std::cin >> input;
    if (std::cin.eof()) {
      clearerr(stdin);
      std::cin.clear();
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (input.length() == 0);
  return (input);
}

int main() {
  PhoneBook phoneBook;
  std::string input;

  do {
    input = getInput("command (ADD | SEARCH | EXIT): ");
    if (input == "ADD") {
      phoneBook.addContact();
    } else if (input == "SEARCH") {
      phoneBook.searchContact();
    }
  } while (input != "EXIT");
}