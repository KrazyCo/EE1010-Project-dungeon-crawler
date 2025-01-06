#pragma once

class Room {
private:
	Room* northRoom;
	Room* southRoom;
	Room* eastRoom;
	Room* westRoom;

public:
	Room();

	void setNorthRoom(Room* room);
	void setSouthRoom(Room* room);
	void setEastRoom(Room* room);
	void setWestRoom(Room* room);
	Room* getNorthRoom();
	Room* getSouthRoom();
	Room* getEastRoom();
	Room* getWestRoom();

};