#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void	add();
	void	search() const;

private:
	Contact	_contacts[8];
	int		_count;	// number of saved contacts, 8 at most
	int		_next;	// index where the next contact will be saved

	std::string	_ask(std::string question) const;
	std::string	_truncate(std::string text) const;
	void		_printTable() const;
	void		_printContact(int index) const;
};

#endif
