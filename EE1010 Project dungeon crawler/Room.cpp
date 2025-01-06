#include "Room.h"

Room::Room()
{
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
