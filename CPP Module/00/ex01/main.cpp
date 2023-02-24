#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

std::string getInput(std::string message)
{
	std::string input;

	do {
		std::cin.clear();
		std::cout << message;
		std::cin >> input;
	} while (input.size() == 0);
	return (input);
}

int main() {

	std::string input;
	PhoneBook phoneBook;

	while (true) {

		std::cin.clear();
		std::cout << "Command(ADD, SEARCH, EXIT) : ";
		std::cin >> input;

		if (input.compare("ADD") == 0) {
			
			Contact contact;

			contact.setInfo();
			phoneBook.setContact(contact);	
			std::cout << "Contact added!" << std::endl;	
		}
		else if (input.compare("SEARCH") == 0) {

			phoneBook.printAll();
			if (phoneBook.getSaveCnt() == 0)
				continue;

			int input;
			do {
				std::cout << "Index : ";
				std::cin.clear();
				std::cin >> input;
			} while (!(0 <= input && input <= 7) || input > phoneBook.getSaveCnt() - 1);
			
			phoneBook.getContact(input).printInfo();	
		}
		else if (input.compare("EXIT") == 0)
			break;
		else
			std::cout << "Wrong Command!" << std::endl;
	}
}