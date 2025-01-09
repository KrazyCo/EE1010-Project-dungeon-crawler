#include "Room.h"
#include "Setup.h"
#include <iostream>

int main()
{
	const int rows = 7;
	const int columns = 7;
	Room rooms[rows][columns];

	Room* currentRoom = &rooms[0][0];

	setup2DArray(rows, columns, rooms, &currentRoom);

	currentRoom->printRoom();
	std::cout << currentRoom->getDescription() << '\n';

	
}

