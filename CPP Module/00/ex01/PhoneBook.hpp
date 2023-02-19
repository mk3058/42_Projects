#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int idx;
public:
	void set_contact(Contact contact);
	Contact get_contact(int idx);
	void print_contacts();
};

#endif