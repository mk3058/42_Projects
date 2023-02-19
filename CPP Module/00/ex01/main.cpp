#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

const std::string get_input(std::string message) {
	
	std::string input;

	do
	{
		std::cout << message;
		std::cin >> input;
	} while (input.length() == 0);
	return (input);
}

void Contact::setInfo() {

	this->first_name = get_input("성을 입력하세요 : ");
	this->last_name = get_input("이름을 입력하세요 : ");
	this->nick_name = get_input("별명을 입력하세요 : ");
	this->phone_number = get_input("전화번호를 입력하세요 : ");
	this->darkest_secret = get_input("비밀을 입력하세요 : ");
}

void Contact::printInfo() {
	std::cout << std::setw(10) << this->first_name << "|" \
			  << std::setw(10) << this->last_name << "|" \
			  << std::setw(10) << this->nick_name\
			  << std::endl;
}

PhoneBook::PhoneBook() {
	this->idx = 0;
}

void PhoneBook::setContact() {

	contacts[this->idx].setInfo();
	idx++;
	idx = idx % 8;
}

Contact PhoneBook::getContact(int idx) {
	
	return (this->contacts[idx]);
}

void PhoneBook::printAllContacts()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name";
	std::cout << std::endl << "----------------------------------------" << std::endl;

	for(int i = 0; i < this->idx; i++)
	{
		std::cout << std::setw(10) << i << "|";
		this->contacts[i].printInfo();
	}
}


int main() {

	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::string input;

		std::cout << "커맨드를 입력하세요(ADD, SEARCH, EXIT) : ";
		std::cin >> command;
		if (command == "ADD" || command == "add")
		{
			phoneBook.setContact();
		}
		else if (command == "SEARCH" || command == "search")
		{
			phoneBook.printAllContacts();
		}
		else if (command == "EXIT" || command == "exit")
		{
			break;
		}
		else
			std::cout << "Wrong command!" << std::endl;
	}
}

