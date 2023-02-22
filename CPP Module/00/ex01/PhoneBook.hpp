#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int	saved;

	public:
		PhoneBook();
		void setContact(Contact contact);
		Contact getContact(int idx);
		void print();
};

#endif