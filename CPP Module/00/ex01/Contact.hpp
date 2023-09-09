#ifndef CONTACT_HPP
#define CONTACT_HPP

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
  static std::string getInput(std::string str);

 public:
  Contact();
  void setContact();
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickname() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;
};

#endif