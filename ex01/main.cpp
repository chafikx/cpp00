#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			return 0;
		// input closed (ctrl-D) in the middle of a command
		if (std::cin.eof())
			break;
	}
	std::cout << std::endl;
	return 0;
}
