#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string value)
{
	_firstName = value;
}

void	Contact::setLastName(std::string value)
{
	_lastName = value;
}

void	Contact::setNickname(std::string value)
{
	_nickname = value;
}

void	Contact::setPhoneNumber(std::string value)
{
	_phoneNumber = value;
}

void	Contact::setDarkestSecret(std::string value)
{
	_darkestSecret = value;
}

std::string	Contact::getFirstName() const
{
	return _firstName;
}

std::string	Contact::getLastName() const
{
	return _lastName;
}

std::string	Contact::getNickname() const
{
	return _nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return _darkestSecret;
}
