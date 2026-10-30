#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::Contact(const std::string &firstName, const std::string &lastName,
	const std::string &nickname, const std::string &phoneNumber,
	const std::string &darkestSecret)
	: _firstName(firstName), _lastName(lastName), _nickname(nickname),
	  _phoneNumber(phoneNumber), _darkestSecret(darkestSecret)
{
}

Contact::~Contact(void)
{
}

const std::string	&Contact::getFirstName(void) const
{
	return _firstName;
}

const std::string	&Contact::getLastName(void) const
{
	return _lastName;
}

const std::string	&Contact::getNickname(void) const
{
	return _nickname;
}

const std::string	&Contact::getPhoneNumber(void) const
{
	return _phoneNumber;
}

const std::string	&Contact::getDarkestSecret(void) const
{
	return _darkestSecret;
}
