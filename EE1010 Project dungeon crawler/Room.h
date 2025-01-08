#pragma once

#include <string>

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

public:
	Room(std::string name, std::string centerText, std::string description, std::string hint);

	void setNorthRoom(Room* room);
	void setSouthRoom(Room* room);
	void setEastRoom(Room* room);
	void setWestRoom(Room* room);
	Room* getNorthRoom();
	Room* getSouthRoom();
	Room* getEastRoom();
	Room* getWestRoom();

	std::string getName();
	std::string getDescription();
	std::string getHint();
	bool getVisited();
	
	void printRoom();
};