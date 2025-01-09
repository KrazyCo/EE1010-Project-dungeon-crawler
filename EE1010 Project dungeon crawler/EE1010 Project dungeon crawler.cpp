#include "Room.h"
#include "Setup.h"
#include "Input.h"
#include "StringFunctions.h"

#include <iostream>
#include <string>

int main()
{
	bool gameRunning = true;
	bool movedRooms = true;

	const int rows = 7;
	const int columns = 7;
	Room rooms[rows][columns];

	Room* currentRoom = &rooms[0][0];

	setup2DArray(rows, columns, rooms, &currentRoom);

	while (gameRunning)
	{
		if (movedRooms)
		{
			currentRoom->printRoom();
			std::cout << '\n' << currentRoom->getDescription() << "\n\n";
			movedRooms = false;
		}
		std::string userInput = getUserString("Enter a direction to move (north/up, south/down, east/right, west/left): ");
		userInput = toLower(userInput);
		if (userInput == "north" || userInput == "up")
		{
			if (currentRoom->moveNorth(&currentRoom))
			{
				std::cout << "\n\n\n\n\n\nYou move north.\n\n\n";
				movedRooms = true;
			}
			else
			{
				std::cout << "You can't move north.\n";
			}
		}
		else if (userInput == "south" || userInput == "down")
		{
			if (currentRoom->moveSouth(&currentRoom))
			{
				std::cout << "\n\n\n\n\n\nYou move south.\n\n\n";
				movedRooms = true;
			}
			else
			{
				std::cout << "You can't move south.\n";
			}
		}
		else if (userInput == "east" || userInput == "right")
		{
			if (currentRoom->moveEast(&currentRoom))
			{
				std::cout << "\n\n\n\n\n\nYou move east.\n\n\n";
				movedRooms = true;
			}
			else
			{
				std::cout << "You can't move east.\n";
			}
		}
		else if (userInput == "west" || userInput == "left")
		{
			if (currentRoom->moveWest(&currentRoom))
			{
				std::cout << "\n\n\n\n\n\nYou move west.\n\n\n";
				movedRooms = true;
			}
			else
			{
				std::cout << "You can't move west.\n";
			}
		}
		else
		{
			std::cout << "Invalid direction.\n";
		}
	}


	
}

