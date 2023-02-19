#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
public:
	void setFirstName(std::string first_name);
	void setLastName(std::string last_name);
	void setNickName(std::string nick_name);
	void setPhoneNumber(std::string phone_number);
};

#endif