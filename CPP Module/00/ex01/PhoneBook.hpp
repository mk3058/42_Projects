#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstdio>
#include <iomanip>
#include <iostream>
#include <limits>

class Contact {
 private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

 public:
  Contact();
  void setContact();
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickname() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;
};

class PhoneBook {
 private:
  Contact contacts[8];
  int idx;
  void displayContacts();
  void displayContact(int idx);

 public:
  PhoneBook();
  void addContact();
  void searchContact();
};

#endif