#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook(void) : _count(0), _oldest(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addContact(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (_count == _maxContacts)
		std::cout << "The phonebook is full: the oldest contact will be replaced."
			<< std::endl;
	// stop as soon as one field can't be read (end of input)
	if (!_readField("First name", firstName)
		|| !_readField("Last name", lastName)
		|| !_readField("Nickname", nickname)
		|| !_readField("Phone number", phoneNumber)
		|| !_readField("Darkest secret", darkestSecret))
		return;
	_contacts[_oldest] = Contact(firstName, lastName, nickname,
		phoneNumber, darkestSecret);
	// once the 8 slots are used, wrap around to overwrite the oldest one
	_oldest = (_oldest + 1) % _maxContacts;
	if (_count < _maxContacts)
		_count++;
	std::cout << "Contact saved." << std::endl;
}

void	PhoneBook::searchContact(void) const
{
	std::string	input;

	if (_count == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return;
	}
	_displayList();
	std::cout << "Index of the contact to display: ";
	if (!std::getline(std::cin, input))
		return;
	if (input.length() != 1 || !std::isdigit(static_cast<unsigned char>(input[0]))
		|| input[0] - '0' >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	_displayContact(input[0] - '0');
}

void	PhoneBook::_displayList(void) const
{
	std::cout << std::setw(_columnWidth) << "Index" << '|'
		<< std::setw(_columnWidth) << "First name" << '|'
		<< std::setw(_columnWidth) << "Last name" << '|'
		<< std::setw(_columnWidth) << "Nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(_columnWidth) << i << '|'
			<< std::setw(_columnWidth) << _truncate(_contacts[i].getFirstName()) << '|'
			<< std::setw(_columnWidth) << _truncate(_contacts[i].getLastName()) << '|'
			<< std::setw(_columnWidth) << _truncate(_contacts[i].getNickname())
			<< std::endl;
	}
}

void	PhoneBook::_displayContact(int index) const
{
	const Contact	&contact = _contacts[index];

	std::cout << "First name:     " << contact.getFirstName() << std::endl;
	std::cout << "Last name:      " << contact.getLastName() << std::endl;
	std::cout << "Nickname:       " << contact.getNickname() << std::endl;
	std::cout << "Phone number:   " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

// Prompts until the user enters a valid value. Returns false on end of input.
bool	PhoneBook::_readField(const std::string &label, std::string &value)
{
	while (true)
	{
		std::cout << label << ": ";
		if (!std::getline(std::cin, value))
			return false;
		if (_isValidField(value))
			return true;
		std::cout << "Invalid input: the field can't be empty or contain"
			<< " control characters (tab, arrow keys...)." << std::endl;
	}
}

// A field must contain at least one non-space character, and no control
// characters, which would break the alignment of the SEARCH table.
bool	PhoneBook::_isValidField(const std::string &value)
{
	bool	hasVisibleChar = false;

	for (std::string::size_type i = 0; i < value.length(); i++)
	{
		unsigned char	c = static_cast<unsigned char>(value[i]);

		if (std::iscntrl(c))
			return false;
		if (!std::isspace(c))
			hasVisibleChar = true;
	}
	return hasVisibleChar;
}

std::string	PhoneBook::_truncate(const std::string &text)
{
	if (text.length() > _columnWidth)
		return text.substr(0, _columnWidth - 1) + ".";
	return text;
}
