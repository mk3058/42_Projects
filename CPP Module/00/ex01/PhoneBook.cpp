#include "Phonebook.hpp"

PhoneBook::PhoneBook() : idx(0) {}

void PhoneBook::addContact() {
  idx %= 8;
  contacts[idx++].setContact();
}

void PhoneBook::displayContacts() {
  std::cout << "+-------------------------------------------+" << std::endl;
  std::cout << "|" << std::setw(10) << "INDEX" << "|" << " FirstName" << "|" << "  LastName" << "|" << "  NickName" << "|" << std::endl;
  std::cout << "+-------------------------------------------+" << std::endl;
  for (int i = 0; i < 8; i++) {
    std::cout << "|" << std::setw(10) << i + 1;
    std::cout << "|" << std::setw(10)
              << ((this->contacts[i].getFirstName().length() > 10)
                      ? this->contacts[i].getFirstName().substr(0, 9) + "."
                      : this->contacts[i].getFirstName());
    std::cout << "|" << std::setw(10)
              << ((this->contacts[i].getLastName().length() > 10)
                      ? this->contacts[i].getLastName().substr(0, 9) + "."
                      : this->contacts[i].getLastName());
    std::cout << "|" << std::setw(10)
              << ((this->contacts[i].getNickname().length() > 10)
                      ? this->contacts[i].getNickname().substr(0, 9) + "."
                      : this->contacts[i].getNickname());
    std::cout << "|" << std::endl;
  }
  std::cout << "+-------------------------------------------+" << std::endl;
}

void PhoneBook::displayContact(int idx) {
  if (idx < 1 || idx > 8) {
    std::cout << "index out of range" << std::endl;
    return;
  }
  idx--;
  std::cout << "first name: " << this->contacts[idx].getFirstName() << std::endl
            << "last name: " << this->contacts[idx].getLastName() << std::endl
            << "Nickname: " << this->contacts[idx].getNickname() << std::endl
            << "phone number: " << this->contacts[idx].getPhoneNumber()
            << std::endl
            << "darkest secret: " << this->contacts[idx].getDarkestSecret()
            << std::endl;
}

void PhoneBook::searchContact() {
  int idx;

  displayContacts();
  do {
    std::cout << "index: ";
    std::cin >> idx;
    if (std::cin.eof()) {
      clearerr(stdin);
      std::cin.clear();
    }
    else if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "index must be an integer" << std::endl;
    }
    else if (!(1 <= idx && idx <= 8)) {
      std::cout << "index out of range" << std::endl;
    }
  } while (!(1 <= idx && idx <= 8));
  displayContact(idx);
}
