#include "Room.h"
#include <string>
#include <iostream>
#include <algorithm>

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
}

void Room::setNorthRoom(Room* room)
{
	northRoom = room;
}

void Room::setSouthRoom(Room* room)
{
	southRoom = room;
}

void Room::setEastRoom(Room* room)
{
	eastRoom = room;
}

void Room::setWestRoom(Room* room)
{
	westRoom = room;
}

Room* Room::getNorthRoom()
{
	return northRoom;
}

Room* Room::getSouthRoom()
{
	return southRoom;
}

Room* Room::getEastRoom()
{
	return eastRoom;
}

Room* Room::getWestRoom()
{
	return westRoom;
}

std::string Room::getName()
{
	return name;
}

std::string Room::getDescription()
{
	return description;
}

std::string Room::getHint()
{
	return hint;
}

bool Room::getVisited()
{
	return visited;
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
					northHintLineLength = northRoom->getHint().find_last_of(" ", northHintStart + northHintLineLength) - northHintStart;
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
	// west room hint, center text and east room hint
	
}