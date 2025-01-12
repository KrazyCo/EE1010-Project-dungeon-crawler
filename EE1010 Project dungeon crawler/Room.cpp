#include "Room.h"
#include "Monster.h"

#include <algorithm>
#include <iostream>
#include <string>

Room::Room()
{
	name = "";
	centerText = "";
	description = "";
	hint = "";
	visited = false;
	northRoom = nullptr;
	southRoom = nullptr;
	eastRoom = nullptr;
	westRoom = nullptr;
	monster = nullptr;
}

Room::Room(std::string name, std::string centerText, std::string description)
{
	this->name = name;
	this->centerText = centerText;
	this->description = description;
	hint = "";
	visited = false;
	northRoom = nullptr;
	southRoom = nullptr;
	eastRoom = nullptr;
	westRoom = nullptr;
	monster = nullptr;
}

Room::Room(std::string name, std::string centerText, std::string description, std::string hint)
{
	this->name = name;
	this->centerText = centerText;
	this->description = description;
	this->hint = hint;
	visited = false;
	northRoom = nullptr;
	southRoom = nullptr;
	eastRoom = nullptr;
	westRoom = nullptr;
	monster = nullptr;
}

Room* Room::getNorthRoom()
{
	if (northRoom)
	{
		return northRoom;
	}
	else
	{
		return nullptr;
	}
}

Room* Room::getSouthRoom()
{
	if (southRoom)
	{
		return southRoom;
	}
	else
	{
		return nullptr;
	}
}

Room* Room::getEastRoom()
{
	if (eastRoom)
	{
		return eastRoom;
	}
	else
	{
		return nullptr;
	}
}

Room* Room::getWestRoom()
{
	if (westRoom)
	{
		return westRoom;
	}
	else
	{
		return nullptr;
	}
}

void Room::printRoom()
{
	// north room hint
	if (northRoom)
	{
		bool endOfNorthHint{ false };
		int spaceAtStartOfNorthHint{ 0 };

		int northHintStart{ 0 };
		int northHintLineLength{ 0 };
		int northHintPadding{ 0 };

		for (int i = 0; i < 3; i++)
		{
			if (!endOfNorthHint)
			{
				northHintStart += northHintLineLength + spaceAtStartOfNorthHint;
				northHintLineLength = std::min(23, static_cast<int>(northRoom->getHint().length() - northHintStart));
				northHintPadding = 0;
				if (northHintLineLength == 23)
				{
					northHintLineLength = static_cast<int>(northRoom->getHint().find_last_of(" ", northHintStart + northHintLineLength)) - northHintStart; // static_cast to get rid of compiler warning
				}
				else
				{
					endOfNorthHint = true;
				}
				northHintPadding = 23 - northHintLineLength;
				std::cout << "#############################################   "
					<< northRoom->getHint().substr(northHintStart, northHintLineLength)
					<< std::string(northHintPadding, ' ')
					<< "   #############################################\n";
				spaceAtStartOfNorthHint = 1;
			}
			else
			{
				std::cout << "#############################################                             #############################################\n";
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << "#######################################################################################################################\n";
		}
	}
	for (int i = 0; i < 7; i++)
	{
		std::cout << "###                                                                                                                 ###\n";
	}

	// west room hint, center text and east room hint
	if (westRoom)
	{
		std::cout << "   ";
	}
	else
	{
		std::cout << "###";
	}

	std::cout << "                                                                                                                 ";

	if (eastRoom)
	{
		std::cout << "   \n";
	}
	else
	{
		std::cout << "###\n";
	}

	bool endOfWestHint{ false };
	int spaceAtStartOfWestHint{ 0 };
	int westHintStart{ 0 };
	int westHintLineLength{ 0 };
	int westHintPadding{ 0 };

	bool endOfCenterText{ false };
	int spaceAtStartOfCenterText{ 0 };
	int centerTextStart{ 0 };
	int centerTextLineLength{ 0 };
	int centerTextPadding{ 0 };

	bool endOfEastHint{ false };
	int spaceAtStartOfEastHint{ 0 };
	int eastHintStart{ 0 };
	int eastHintLineLength{ 0 };
	int eastHintPadding{ 0 };

	for (int i = 0; i < 3; i++)
	{
		if (westRoom)
		{

			if (!endOfWestHint)
			{
				westHintStart += westHintLineLength + spaceAtStartOfWestHint;
				westHintLineLength = std::min(23, static_cast<int>(westRoom->getHint().length() - westHintStart));
				westHintPadding = 0;
				if (westHintLineLength == 23)
				{
					westHintLineLength = static_cast<int>(westRoom->getHint().find_last_of(" ", westHintStart + westHintLineLength)) - westHintStart; // static_cast to get rid of compiler warning
				}
				else
				{
					endOfWestHint = true;
				}
				westHintPadding = 23 - westHintLineLength;
				std::cout << westRoom->getHint().substr(westHintStart, westHintLineLength)
					<< std::string(westHintPadding, ' ');
				spaceAtStartOfWestHint = 1;
			}
			else
			{
				std::cout << "                       ";
			}
		}
		else
		{
			std::cout << "###                    ";
		}



		std::cout << "             ";

		if (!endOfCenterText)
		{
			centerTextStart += centerTextLineLength + spaceAtStartOfCenterText;
			centerTextLineLength = std::min(50, static_cast<int>(centerText.length() - centerTextStart));
			centerTextPadding = 0;
			if (centerTextLineLength == 50)
			{
				centerTextLineLength = static_cast<int>(centerText.find_last_of(" ", centerTextStart + centerTextLineLength)) - centerTextStart; // static_cast to get rid of compiler warning
			}
			else
			{
				endOfCenterText = true;
			}
			centerTextPadding = 50 - centerTextLineLength;
			std::cout << centerText.substr(centerTextStart, centerTextLineLength)
				<< std::string(centerTextPadding, ' ');
			spaceAtStartOfCenterText = 1;
		}
		else
		{
			std::cout << "                                                  ";
		}

		std::cout << "          ";

		if (eastRoom)
		{
			if (!endOfEastHint)
			{
				eastHintStart += eastHintLineLength + spaceAtStartOfEastHint;
				eastHintLineLength = std::min(23, static_cast<int>(eastRoom->getHint().length() - eastHintStart));
				eastHintPadding = 0;
				if (eastHintLineLength == 23)
				{
					eastHintLineLength = static_cast<int>(eastRoom->getHint().find_last_of(" ", eastHintStart + eastHintLineLength)) - eastHintStart; // static_cast to get rid of compiler warning
				}
				else
				{
					endOfEastHint = true;
				}
				eastHintPadding = 23 - eastHintLineLength;
				std::cout << eastRoom->getHint().substr(eastHintStart, eastHintLineLength)
					<< std::string(eastHintPadding, ' ') << '\n';
				spaceAtStartOfEastHint = 1;
			}
			else
			{
				std::cout << "                       \n";
			}
		}
		else
		{
			std::cout << "                    ###\n";
		}
	}

	if (westRoom)
	{
		std::cout << "   ";
	}
	else
	{
		std::cout << "###";
	}

	if (monster)
	{
		std::cout << "                                ";
		constexpr int damageChars{ 40 };
		// static_cast hell is to stop compiler warnings but still use floating division
		int monsterAlivenessAmount = static_cast<int>((static_cast<float>(monster->getHealth())) / static_cast<float>(monster->getMaxHealth()) * static_cast<float>(damageChars));
		monsterAlivenessAmount = std::max(monsterAlivenessAmount, 0);

		std::cout << '[' << std::string(static_cast<int>(monsterAlivenessAmount), '#') << std::string(damageChars - static_cast<int>(monsterAlivenessAmount), ' ') << ']';
		std::cout << ' ' << monster->getHealth() << "hp / " << monster->getMaxHealth() << "hp";

		if (monster->getHealth() < 10) { std::cout << ' '; } // add padding if the health is 1 digit

		std::cout << "                           ";
	}
	else
	{
		std::cout << "                                                                                                                 ";
	}

	if (eastRoom)
	{
		std::cout << "   \n";
	}
	else
	{
		std::cout << "###\n";
	}

	for (int i = 0; i < 7; i++)
	{
		std::cout << "###                                                                                                                 ###\n";
	}

	// south room hint
	if (southRoom)
	{
		bool endOfSouthHint{ false };
		int spaceAtStartOfSouthHint{ 0 };
		int southHintStart{ 0 };
		int southHintLineLength{ 0 };
		int southHintPadding{ 0 };
		for (int i = 0; i < 3; i++)
		{
			if (!endOfSouthHint)
			{
				southHintStart += southHintLineLength + spaceAtStartOfSouthHint;
				southHintLineLength = std::min(23, static_cast<int>(southRoom->getHint().length() - southHintStart));
				southHintPadding = 0;
				if (southHintLineLength == 23)
				{
					southHintLineLength = static_cast<int>(southRoom->getHint().find_last_of(" ", southHintStart + southHintLineLength)) - southHintStart; // static_cast to get rid of compiler warning
				}
				else
				{
					endOfSouthHint = true;
				}
				southHintPadding = 23 - southHintLineLength;
				std::cout << "#############################################   "
					<< southRoom->getHint().substr(southHintStart, southHintLineLength)
					<< std::string(southHintPadding, ' ')
					<< "   #############################################\n";
				spaceAtStartOfSouthHint = 1;
			}
			else
			{
				std::cout << "#############################################                             #############################################\n";
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << "#######################################################################################################################\n";
		}
	}
}

void Room::setMonster(Monster* monster)
{
	this->monster = monster;
}

bool Room::moveUp(Room** outRoom)
{
	if (northRoom)
	{
		*outRoom = northRoom;
		return true;
	}
	else
	{
		return false;
	}
}

bool Room::moveDown(Room** outRoom)
{
	if (southRoom)
	{
		*outRoom = southRoom;
		return true;
	}
	else
	{
		return false;
	}
}

bool Room::moveRight(Room** outRoom)
{
	if (eastRoom)
	{
		*outRoom = eastRoom;
		return true;
	}
	else
	{
		return false;
	}
}

bool Room::moveLeft(Room** outRoom)
{
	if (westRoom)
	{
		*outRoom = westRoom;
		return true;
	}
	else
	{
		return false;
	}
}

void Room::pickupItem(float& playerAttack, float& playerDefence, bool& hasEndKey)
{
	bool itemPickedUp{ false };

	switch (this->item.type)
	{
	case ItemType::NONE:
		std::cout << "There is nothing to pick up here.\n";
		return;
		break;
	case ItemType::KEY:
		std::cout << "You picked up a " << item.name << ".\n";
		if (item.keyType == KeyType::END_GATE)
		{
			hasEndKey = true;
		}
		itemPickedUp = true;
		break;
	case ItemType::SWORD:
		if (item.attack > playerAttack)
		{
			playerAttack = item.attack;
			std::cout << "You picked up a " << item.name << ".\n";
			itemPickedUp = true;
		}
		else
		{
			std::cout << "As you inspect the sword, you realise you already have a better one, so you do not pick it up.\n";
		} 
		break;
	case ItemType::SHIELD:
		if (item.defense > playerDefence)
		{
			playerDefence = item.defense;
			std::cout << "You picked up a " << item.name << ".\n";
			itemPickedUp = true;
		}
		else
		{
			std::cout << "As you inspect the shield, you realise you already have a better one, so you do not pick it up.\n";
		}
		break;
	}

	if (itemPickedUp)
	{
		// as the item has now been picked up remove it from the room
		this->centerText = "";
		this->description = "An empty room you can pass freely through";
		this->item.type = ItemType::NONE;
		this->item.attack = 0;
		this->item.defense = 0;
		this->item.name = "";
		this->item.keyType = KeyType::NONE;
	}
}