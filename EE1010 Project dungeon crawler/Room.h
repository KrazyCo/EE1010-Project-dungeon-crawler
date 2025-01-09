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

	std::string getName() { return name; }
	std::string getDescription() { return description; }
	std::string getHint() { return hint; }
	bool getVisited() { return visited; }

	void setName(std::string name) { this->name = name; }
	void setDescription(std::string description) { this->description = description; }
	void setHint(std::string hint) { this->hint = hint; }
	void setVisited(bool visited) { this->visited = visited; }

	bool moveNorth(Room** outRoom);
	bool moveSouth(Room** outRoom);
	bool moveEast(Room** outRoom);
	bool moveWest(Room** outRoom);
	
	void printRoom();
};
