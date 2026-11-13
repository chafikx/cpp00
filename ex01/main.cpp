#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	// good() becomes false when the input is closed (ctrl-D)
	while (std::cin.good())
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			break;
	}
	return 0;
}
