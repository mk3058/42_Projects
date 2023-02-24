#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	saved = 0;
}

std::string PhoneBook::setWidth(std::string str) {
	
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void PhoneBook::setContact(Contact contact) {
	
	int idx = saved % 8;

	contacts[idx] = contact;
	saved++;
}

int	PhoneBook::getSaveCnt() {
	return (saved);
}

Contact PhoneBook::getContact(int idx) {

	if (!(0 <= idx && idx <= 7))
		throw std::out_of_range("getContact : index out of bounds!");
	else
		return (contacts[idx]);
}

void PhoneBook::printAll()
{
	int i = 0;

	std::cout << std::right;
	std::cout << std::setw(10) << "index" << "|"\
			  << std::setw(10) << "first name" << "|"\
			  << std::setw(10) << "last name" << "|"\
			  << std::setw(10) << "nickname" << std::endl;
	while (i < saved && i < 8) {
		std::cout << std::setw(10) << i << "|"\
			  	  << std::setw(10) << setWidth(contacts[i].getFirstName()) << "|"\
			  	  << std::setw(10) << setWidth(contacts[i].getLastName()) << "|"\
			  	  << std::setw(10) << setWidth(contacts[i].getNickName()) << std::endl;
		i++;
	}
	std::cout << std::left;
}
