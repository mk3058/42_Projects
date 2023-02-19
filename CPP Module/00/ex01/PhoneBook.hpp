#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int idx;
public:
	PhoneBook();
	void setContact();
	Contact getContact(int idx);
	void printAllContacts();
};

#endif