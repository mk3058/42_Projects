#include "Contact.hpp"

std::string Contact::getInput(std::string str) {
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

Contact::Contact()
    : firstName("No data"),
      lastName("No data"),
      nickname("No data"),
      phoneNumber("No data"),
      darkestSecret("No data") {}

void Contact::setContact() {
  std::string input;

  this->firstName = getInput("first name: ");
  this->lastName = getInput("last name: ");
  this->nickname = getInput("nick name: ");
  this->phoneNumber = getInput("phone number: ");
  this->darkestSecret = getInput("darkest secret: ");
}

std::string Contact::getFirstName() const { return (this->firstName); }
std::string Contact::getLastName() const { return (this->lastName); }
std::string Contact::getNickname() const { return (this->nickname); }
std::string Contact::getPhoneNumber() const { return (this->phoneNumber); }
std::string Contact::getDarkestSecret() const { return (this->darkestSecret); }
