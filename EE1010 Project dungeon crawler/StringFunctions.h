#pragma once

#include <string>

std::string toLower(std::string& str)
{
	std::string lowerStr;
	for (char c : str)
	{
		lowerStr += std::tolower(c);
	}
	return lowerStr;
}
