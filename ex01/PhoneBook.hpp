#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	searchContact(void) const;

private:
	static const int	_maxContacts = 8;
	static const int	_columnWidth = 10;

	Contact	_contacts[_maxContacts];
	int		_count;		// number of saved contacts
	int		_oldest;	// slot the next contact will be written to

	void				_displayList(void) const;
	void				_displayContact(int index) const;
	static bool			_readField(const std::string &label, std::string &value);
	static bool			_isValidField(const std::string &value);
	static std::string	_truncate(const std::string &text);
};

#endif
