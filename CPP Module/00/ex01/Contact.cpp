#include "Contact.hpp"

std::string getInput(std::string message);

void Contact::setInfo() {
	first_name = getInput("First Name : ");
	last_name = getInput("Last Name : ");
	nick_name = getInput("Nick Name : ");
	phone_number = getInput("Phone Number : ");
	darkest_secret = getInput("Darkest Secret : ");
}

void Contact::printInfo() {
	std::cout << "First Name : " << first_name << std::endl\
			  << "Last Name : " << last_name << std::endl\
			  << "Nick Name : " << nick_name << std::endl\
			  << "Phone Number : " << phone_number << std::endl\
			  << "Darkest Secret : " << darkest_secret << std::endl;
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
