#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _count(0), _next(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	Contact	contact;

	contact.setFirstName(_ask("First name: "));
	contact.setLastName(_ask("Last name: "));
	contact.setNickname(_ask("Nickname: "));
	contact.setPhoneNumber(_ask("Phone number: "));
	contact.setDarkestSecret(_ask("Darkest secret: "));
	// input closed (ctrl-D) before the end: nothing is saved
	if (!std::cin.good())
		return;
	_contacts[_next] = contact;
	// after index 7 comes index 0 again: the oldest contact gets replaced
	_next = (_next + 1) % 8;
	if (_count < 8)
		_count++;
	std::cout << "Contact saved." << std::endl;
}

void	PhoneBook::search() const
{
	std::string	input;
	int			index = -1;

	if (_count == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return;
	}
	_printTable();
	std::cout << "Index of the contact to display: ";
	std::getline(std::cin, input);
	if (input.length() == 1)
		index = input[0] - '0';
	if (index < 0 || index >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	_printContact(index);
}

// Asks the question again until the answer is not empty.
std::string	PhoneBook::_ask(std::string question) const
{
	std::string	answer;

	while (answer.empty() && std::cin.good())
	{
		std::cout << question;
		std::getline(std::cin, answer);
	}
	return answer;
}

std::string	PhoneBook::_truncate(std::string text) const
{
	if (text.length() > 10)
		return text.substr(0, 9) + ".";
	return text;
}

void	PhoneBook::_printTable() const
{
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First name" << "|"
		<< std::setw(10) << "Last name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << _truncate(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << _truncate(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << _truncate(_contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::_printContact(int index) const
{
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}
