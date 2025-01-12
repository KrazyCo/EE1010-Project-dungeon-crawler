#pragma once

#include <string>
#include <utility>

#include "Items.h"
#include "Monster.h"

enum class RoomDirection
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Room {
private:
	Room* northRoom;
	Room* southRoom;
	Room* eastRoom;
	Room* westRoom;

	std::string name;
	std::string centerText;
	std::string description;
	std::string hint;
	bool visited;
	RoomDirection roomCameFrom;
	Item item;
	Monster* monster;

public:
	Room();
	Room(std::string name, std::string centerText, std::string description);
	Room(std::string name, std::string centerText, std::string description, std::string hint);

	void setNorthRoom(Room* room) { northRoom = room; }
	void setSouthRoom(Room* room) { southRoom = room; }
	void setEastRoom(Room* room) { eastRoom = room; }
	void setWestRoom(Room* room) { westRoom = room; }
	Room* getNorthRoom();
	Room* getSouthRoom();
	Room* getEastRoom();
	Room* getWestRoom();

	bool isRoomNorth() { return northRoom; }
	bool isRoomSouth() { return southRoom; }
	bool isRoomEast() { return eastRoom; }
	bool isRoomWest() { return westRoom; }

	bool isNorthRoomEndRoom() { return (northRoom->getName() == "endMonsterRoom"); }

	std::string getName() { return name; }
	std::string getDescription() { return description; }
	std::string getHint() { return hint; }
	bool getVisited() { return visited; }
	RoomDirection getRoomCameFrom() { return roomCameFrom; }
	Item getItem() { return item; }
	Monster* getMonster() { return monster; }

	void setName(const std::string& name) { this->name = name; }
	void setDescription(const std::string& description) { this->description = description; }
	void setCenterText(const std::string& centerText) { this->centerText = centerText; }
	void setHint(const std::string& hint) { this->hint = hint; }
	void setVisited(bool visited) { this->visited = visited; }
	void setItem(Item& item) { this->item = std::move(item); }
	void setMonster(Monster* monster);
	void setRoomCameFrom(RoomDirection roomDirection) { roomCameFrom = roomDirection; }

	bool moveUp(Room** outRoom);
	bool moveDown(Room** outRoom);
	bool moveRight(Room** outRoom);
	bool moveLeft(Room** outRoom);

	void pickupItem(float& playerAttack, float& playerDefence, bool& hasEndKey);
	
	void printRoom();

};
