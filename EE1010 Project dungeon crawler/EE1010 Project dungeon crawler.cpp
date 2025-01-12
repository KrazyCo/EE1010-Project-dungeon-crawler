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

	bool shouldExit{ false };
	bool startOfGame{ true };
	bool playerChosenStart{ false };
	while (!shouldExit)
	{
		if (startOfGame)
		{
			startOfGame = false;
			std::cout << "\n\n\n" // https://patorjk.com/software/taag/#p=testall&f=Chiseled&t=DUNGEONS for the ascii art
				"                    $$$$$$$\\  $$\\   $$\\ $$\\   $$\\  $$$$$$\\  $$$$$$$$\\  $$$$$$\\  $$\\   $$\\  $$$$$$\\\n"
				"                    $$  __$$\\ $$ |  $$ |$$$\\  $$ |$$  __$$\\ $$  _____|$$  __$$\\ $$$\\  $$ |$$  __$$\\ \n"
				"                    $$ |  $$ |$$ |  $$ |$$$$\\ $$ |$$ /  \\__|$$ |      $$ /  $$ |$$$$\\ $$ |$$ /  \\__|\n"
				"                    $$ |  $$ |$$ |  $$ |$$ $$\\$$ |$$ |$$$$\\ $$$$$\\    $$ |  $$ |$$ $$\\$$ |\\$$$$$$\\\n"
				"                    $$ |  $$ |$$ |  $$ |$$ \\$$$$ |$$ |\\_$$ |$$  __|   $$ |  $$ |$$ \\$$$$ | \\____$$\\ \n"
				"                    $$ |  $$ |$$ |  $$ |$$ |\\$$$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |\\$$$ |$$\\   $$ |\n"
				"                    $$$$$$$  |\\$$$$$$  |$$ | \\$$ |\\$$$$$$  |$$$$$$$$\\  $$$$$$  |$$ | \\$$ |\\$$$$$$  |\n"
				"                    \\_______/  \\______/ \\__|  \\__| \\______/ \\________| \\______/ \\__|  \\__| \\______/ \n\n\n";
			while (!playerChosenStart)
			{
				std::cout << "\n"
					"                         _____________                ____________                ____________\n"
					"                        /             \\              /            \\              /            \\\n"
					"                        |    START    |              |    HELP    |              |    EXIT    |\n"
					"                        \\_____________/              \\____________/              \\____________/\n";
				std::cout << "\n\n\n                        ";

				std::string userInput = getUserString("-> ");
				userInput = toLower(userInput);

				if (userInput == "start")
				{
					playerChosenStart = true;
					std::cout << "\n\n\n\n\n\n";
				}
				else if (userInput == "help")
				{
					// explain game to user
					std::cout << "\n"
						"                        Welcome to Dungeons, where you have to defeat the final monster to win!\n"
						"                        While playing the game, you have a few options of choices you can make,\n"
						"                        these are shown in brackets().\n"
						"                        You can find items (swords and shields) around the dungeon to help you\n"
						"                        fight monsters, they will be required for some of them!\n"
						"                        When you defeat a monster, you will make a health potion and heal up\n"
						"                        slightly depending on how strong the monster was, \n"
						"                        so if you are low health you can go kill monsters to heal up enough.\n"
						"                        The room to the final monster is locked by a gate, so you will need\n"
						"                        to find the key in the dungeon to be able to enter the final room.\n";
				}
				else if (userInput == "exit")
				{
					return 1;
				}
				else
				{
					std::cout << "                        Invalid selection\n";
				}
			}
			playerChosenStart = false;
		}
		else // if player has finsihed the game, either by losing or winning
		{
			bool playerChosenStart{ false };
			while (!playerChosenStart)
			{
				std::string userInput = getUserString("-> ");
				userInput = toLower(userInput);

				if (userInput == "start")
				{
					playerChosenStart = true;
					std::cout << "\n\n\n\n\n\n";
				}
				else if (userInput == "help")
				{
					// explain game to user
					std::cout << "blah blah\n";
				}
				else if (userInput == "exit")
				{
					return 1;
				}
				else
				{
					std::cout << "Invalid selection. Enter either (start), (help), or (exit)\n";
				}
			}
		}
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
			std::cout << "You can also (pickup) items. You can (exit) the game if you give up.\n\n";

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
					std::cout << "You have died.\n\n";
					std::cout << "You can (start) to play again, you can have (help) if you need it, or you can (exit) the game.\n";
					gameRunning = false;
				}
			}
			else if (userInput == "exit")
			{
				startOfGame = true;
				gameRunning = false;
			}
			else
			{
				std::cout << "Invalid selection.\n\n";
			}

			// win condition
			if (currentRoom->getName() == "endMonsterRoom" && !(currentRoom->getMonster()->getIsAlive()))
			{
				std::cout << "Congratulations on beating the final monster!\n"
					"You ended the game on " << health << " health!\n\n"
					"You can (start) to play again, you can have (help) if you need it, or you can (exit) the game.\n";
				gameRunning = false;
			}
		}
	}
}

