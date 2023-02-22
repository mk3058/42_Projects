#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

void Contact::setInfo() {
	first_name = getInput("First Name : ");
	last_name = getInput("Last Name : ");
	nick_name = getInput("Nick Name : ");
	phone_number = getInput("Phone Number : ");
	darkest_secret = getInput("Darkest Secret : ");
}

std::string Contact::getFirstName() {
	return (first_name);
}

std::string Contact::getLastName() {
	return (last_name);
}

std::string Contact::getNickName() {
	return (nick_name);
}

std::string Contact::getPhoneNumber() {
	return (phone_number);
}

std::string Contact::getDatkestSecret() {
	return (darkest_secret);
}

void PhoneBook::setContact(Contact contact) {
	
	int idx = saved % 8;

	contacts[idx] = contact;
}

Contact PhoneBook::getContact(int idx) {

	if (!(0 <= idx && idx <= 7))
		std::cout << "getContact : index out of bounds!" << std::endl;
	else
		return (contacts[idx]);
}

std::string getInput(std::string message)
{
	std::string input;

	do {
		std::cout << message;
		std::cin >> input;
	} while (input.size() == 0);

	return (input);
}

int main() {
	
}