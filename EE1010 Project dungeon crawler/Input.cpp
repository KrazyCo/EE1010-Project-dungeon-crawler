#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getUserString(std::string prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::string userInput;
		std::getline(std::cin, userInput);
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Please try again.\n";
		}
		else
		{
			return userInput;
		}
	}
}