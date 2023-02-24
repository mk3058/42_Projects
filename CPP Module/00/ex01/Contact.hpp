#ifndef Contact_HPP
# define Contact_HPP

# include <string>
# include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void setInfo();
		void printInfo();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDatkestSecret();
};

#endif