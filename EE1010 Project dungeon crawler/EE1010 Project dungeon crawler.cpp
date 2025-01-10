#include "Room.h"
#include "Setup.h"
#include "Input.h"
#include "StringFunctions.h"
#include "Random.h"

#include <iostream>
#include <string>

int main()
{
	setupRandomSeed();

	bool gameRunning = true;
	bool movedRooms = true;

	float playerAttack{ 0 };
	float playerDefense{ 0 };
	bool hasEndKey{ false };

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

		std::cout << "\nYou can move (up), (down), (left), or (right).\n";
		std::cout << "You can also (pickup) items.\n\n";

		std::string userInput = getUserString("Enter your move: ");
		userInput = toLower(userInput);

		std::cout << '\n';

		if (userInput == "up")
		{
			if (currentRoom->moveUp(&currentRoom))
			{
				std::cout << "\n\n\n\n\n\nYou move up.\n\n\n";
				movedRooms = true;
			}
			else
			{
				std::cout << "You can't move up.\n";
			}
		}
		else if (userInput == "down")
		{
			if (currentRoom->moveDown(&currentRoom))
			{
				std::cout << "\n\n\n\n\n\nYou move down.\n\n\n";
				movedRooms = true;
			}
			else
			{
				std::cout << "You can't move down.\n";
			}
		}
		else if (userInput == "right")
		{
			if (currentRoom->moveRight(&currentRoom))
			{
				std::cout << "\n\n\n\n\n\nYou move right.\n\n\n";
				movedRooms = true;
			}
			else
			{
				std::cout << "You can't move right.\n";
			}
		}
		else if (userInput == "left")
		{
			if (currentRoom->moveLeft(&currentRoom))
			{
				std::cout << "\n\n\n\n\n\nYou move left.\n\n\n";
				movedRooms = true;
			}
			else
			{
				std::cout << "You can't move left.\n";
			}
		}
		else if (userInput == "pickup")
		{
			currentRoom->pickupItem(playerAttack, playerDefense, hasEndKey);
		}
		else
		{
			std::cout << "Invalid selection.\n";
		}
	}


	
}

