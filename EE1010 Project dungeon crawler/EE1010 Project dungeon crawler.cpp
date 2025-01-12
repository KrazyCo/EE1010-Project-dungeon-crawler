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

	float playerAttack{ 5 }; // starting stats
	float playerDefense{ 5 };
	float playerDodgeChance{ 10 };
	bool hasEndKey{ false };
	int health{ 100 };

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

		std::cout << "You can move (up), (down), (left), or (right).\n";
		std::cout << "If you encounter a monster, you can (attack) them to try defeat it.\n";
		std::cout << "You can also (pickup) items.\n\n";

		std::string userInput = getUserString("Enter your move: ");
		userInput = toLower(userInput);

		std::cout << '\n';

		if (userInput == "up")
		{
			if (currentRoom->isRoomNorth())
			{
				if (currentRoom->isNorthRoomEndRoom()) // only the north direction can have an end room
				{
					if (hasEndKey)
					{
						currentRoom->moveUp(&currentRoom);
						currentRoom->setRoomCameFrom(RoomDirection::SOUTH);
						std::cout << "\n\n\n\n\n\nYou pass through the unlocked gate.\n\n\n";
						movedRooms = true;
					}
					else
					{
						std::cout << "A locked gate blocks your path\n\n";
					}
				}
				else
				{
					if (currentRoom->getMonster())// check to make sure that we dont nullptr the if statement below
					{
						if (currentRoom->getMonster()->getIsAlive())
						{
							if (currentRoom->getRoomCameFrom() == RoomDirection::NORTH)
							{
								currentRoom->moveUp(&currentRoom);
								currentRoom->setRoomCameFrom(RoomDirection::SOUTH);
								std::cout << "\n\n\n\n\n\nYou move back up.\n\n\n";
								movedRooms = true;
							}
							else
							{
								std::cout << "The monster blocks you from moving that way, only allowing you to retreat\n\n";
							}
						}
						else
						{
							currentRoom->moveUp(&currentRoom);
							currentRoom->setRoomCameFrom(RoomDirection::SOUTH);
							std::cout << "\n\n\n\n\n\nYou move up.\n\n\n";
							movedRooms = true;
						}
					}
					else
					{
						currentRoom->moveUp(&currentRoom);
						currentRoom->setRoomCameFrom(RoomDirection::SOUTH);
						std::cout << "\n\n\n\n\n\nYou move up.\n\n\n";
						movedRooms = true;
					}
				}
			}
			else
			{
				std::cout << "You can't move up.\n";
			}
		}
		else if (userInput == "down")
		{
			if (currentRoom->isRoomSouth())
			{
				if (currentRoom->getMonster()) // check to make sure that we dont nullptr the if statement below
				{
					if (currentRoom->getMonster()->getIsAlive())
					{
						if (currentRoom->getRoomCameFrom() == RoomDirection::SOUTH)
						{
							currentRoom->moveDown(&currentRoom);
							currentRoom->setRoomCameFrom(RoomDirection::NORTH);
							std::cout << "\n\n\n\n\n\nYou move back down.\n\n\n";
							movedRooms = true;
						}
						else
						{
							std::cout << "The monster blocks you from moving that way, only allowing you to retreat\n\n";
						}
					}
					else
					{
						currentRoom->moveDown(&currentRoom);
						currentRoom->setRoomCameFrom(RoomDirection::NORTH);
						std::cout << "\n\n\n\n\n\nYou move down.\n\n\n";
						movedRooms = true;
					}
				}
				else
				{
					currentRoom->moveDown(&currentRoom);
					currentRoom->setRoomCameFrom(RoomDirection::NORTH);
					std::cout << "\n\n\n\n\n\nYou move down.\n\n\n";
					movedRooms = true;
				}
			}
			else
			{
				std::cout << "You can't move down.\n";
			}
		}
		else if (userInput == "right")
		{
			if (currentRoom->isRoomEast())
			{
				if (currentRoom->getMonster()) // check to make sure that we dont nullptr the if statement below
				{
					if (currentRoom->getMonster()->getIsAlive())
					{
						if (currentRoom->getRoomCameFrom() == RoomDirection::EAST)
						{
							currentRoom->moveRight(&currentRoom);
							currentRoom->setRoomCameFrom(RoomDirection::WEST);
							std::cout << "\n\n\n\n\n\nYou move back right.\n\n\n";
							movedRooms = true;
						}
						else
						{
							std::cout << "The monster blocks you from moving that way, only allowing you to retreat\n\n";
						}
					}
					else
					{
						currentRoom->moveRight(&currentRoom);
						currentRoom->setRoomCameFrom(RoomDirection::WEST);
						std::cout << "\n\n\n\n\n\nYou move right.\n\n\n";
						movedRooms = true;
					}
				}
				else
				{
					currentRoom->moveRight(&currentRoom);
					currentRoom->setRoomCameFrom(RoomDirection::WEST);
					std::cout << "\n\n\n\n\n\nYou move right.\n\n\n";
					movedRooms = true;
				}
			}
			else
			{
				std::cout << "You can't move right.\n";
			}
		}
		else if (userInput == "left")
		{
			if (currentRoom->isRoomWest())
			{
				if (currentRoom->getMonster())// check to make sure that we dont nullptr the if statement below
				{
					if (currentRoom->getMonster()->getIsAlive())
					{
						if (currentRoom->getRoomCameFrom() == RoomDirection::WEST)
						{
							currentRoom->moveLeft(&currentRoom);
							currentRoom->setRoomCameFrom(RoomDirection::EAST);
							std::cout << "\n\n\n\n\n\nYou move back left.\n\n\n";
							movedRooms = true;
						}
						else
						{
							std::cout << "The monster blocks you from moving that way, only allowing you to retreat\n\n";
						}
					}
					else
					{
						currentRoom->moveLeft(&currentRoom);
						currentRoom->setRoomCameFrom(RoomDirection::EAST);
						std::cout << "\n\n\n\n\n\nYou move left.\n\n\n";
						movedRooms = true;
					}
				}
				else
				{
					currentRoom->moveLeft(&currentRoom);
					currentRoom->setRoomCameFrom(RoomDirection::EAST);
					std::cout << "\n\n\n\n\n\nYou move left.\n\n\n";
					movedRooms = true;
				}
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
		else if (userInput == "attack")
		{
			if (currentRoom->getMonster())
			{
				currentRoom->getMonster()->attackMonster(health, playerAttack, playerDefense, 0);
			}
			else
			{
				std::cout << "There is no monster in this room.\n";
			}
			std::cout << "\nYou have " << health << " health left.\n\n";
			if (health <= 0)
			{
				std::cout << "You have died.\n";
				gameRunning = false;
			}
		}
		else if (userInput == "exit")
		{
			gameRunning = false;
		}
		else
		{
			std::cout << "Invalid selection.\n\n";
		}
	}


	
}

