#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int	saved;

		std::string setWidth(std::string str);

	public:
		PhoneBook();
		void setContact(Contact contact);
		int getSaveCnt();
		Contact getContact(int idx);
		void printAll();
};

#endif