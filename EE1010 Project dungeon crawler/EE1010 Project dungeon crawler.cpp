#include "Room.h"
#include <iostream>

void testPrintRoom()
{
	//std::cout << "##########################################                                    ##########################################\n";
	std::cout << "#############################################   A mysterious whistling    #############################################\n";
	std::cout << "#############################################   noise comes from here     #############################################\n";
	std::cout << "#############################################                             #############################################\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "                                                                                                                       \n";
	std::cout << "                                                                                                                       \n";
	std::cout << "                                             a key sits in the middle of the room                                      \n";
	std::cout << "                                                                                                                       \n";
	std::cout << "                                                                                                                       \n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "###                                                                                                                 ###\n";
	std::cout << "#############################################                             #############################################\n";
	std::cout << "#############################################                             #############################################\n";
	std::cout << "#############################################                             #############################################\n";


}

int main()
{
	Room startRoom("startRoom", "A key sits in the middle of the room bleh bleh blah blah blah bleh", "startRoomDescription", "This feels like where you came from");

	Room northRoom("northRoom", "A north sits in the middle of the room", "north description", "A mysterious whistling noise comes from the north");
	Room southRoom("southRoom", "A south sits in the middle of the room", "south description", "A mysterious whistling noise comes from the south");
	Room eastRoom("eastRoom", "A east sits in the middle of the room", "east description", "A mysterious whistling noise comes from the east");
	Room westRoom("westRoom", "A west sits in the middle of the room", "west description", "A mysterious whistling noise comes from the west");

	startRoom.setNorthRoom(&northRoom);
	startRoom.setSouthRoom(&southRoom);
	startRoom.setEastRoom(&eastRoom);
	startRoom.setWestRoom(&westRoom);

	startRoom.printRoom();

	//testPrintRoom();
}

