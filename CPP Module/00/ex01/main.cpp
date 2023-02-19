#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() {
	this->idx = 0;
}

void PhoneBook::set_contact(Contact contact) {
	this->contact[this->idx] = contact;
	this->idx = (this->idx + 1) % 8;
}

Contact PhoneBook::get_contact(int idx) {
	return (this->contact[idx]);
}

void PhoneBook::print_contacts() {
	for (int i = 0; i < this->idx; i++)
	{
		
	}
}

int main()
{
	int idx = 0;
	std::string cmd;
	PhoneBook phoneBook;

	while (true)
	{
		std::cout << "커맨드를 입력하세요 (EXIT, ADD, SEARCH)" << std::endl;
		std::cin >> cmd;

		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
		{
			Contact contact;
			std::string input;

			std::cout << "성을 입력하세요 : ";
			std::cin >> input;
			contact.setFirstName(input);
			std::cout << "이름을 입력하세요 : ";
			std::cin >> input;
			contact.setLastName(input);
			std::cout << "별명을 입력하세요 : ";
			std::cin >> input;
			contact.setNickName(input);
			std::cout << "전화번호를 입력하세요 : ";
			std::cin >> input;
			contact.setPhoneNumber(input);

			phoneBook.set_contact(contact, idx % 8);
			idx++;
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			int input;

			phoneBook.print_contacts();
			std::cout << "인덱스를 입력하세요 : ";
			std::cin >> input;
			
		}
	}
}