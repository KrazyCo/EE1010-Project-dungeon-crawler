#include "Room.h"
#include <string>
#include <iostream>

Room::Room(std::string name, std::string description, std::string hint)
{
	this->name = name;
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
	std::cout << "You are in the " << name << ".\n";
	std::cout << description << "\n";
	std::cout << hint << "\n";
}