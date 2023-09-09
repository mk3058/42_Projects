#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstdio>
#include <iomanip>
#include <iostream>
#include <limits>
#include "Contact.hpp"

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