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
	Room startRoom("startRoom", "A key sits in the middle of the room", "This feels like where you came from");

	Room northRoom("northRoom", "A north sits in the middle of the room", "A mysterious whistling noise comes from the north");
	Room southRoom("southRoom", "A south sits in the middle of the room", "A mysterious whistling noise comes from the south");
	Room eastRoom("eastRoom", "A east sits in the middle of the room", "A mysterious whistling noise comes from the east");
	Room westRoom("westRoom", "A west sits in the middle of the room", "A mysterious whistling noise comes from the west");

	startRoom.setNorthRoom(&northRoom);
	startRoom.setSouthRoom(&southRoom);
	startRoom.setEastRoom(&eastRoom);
	startRoom.setWestRoom(&westRoom);

	//startRoom.printRoom();

    testPrintRoom();
}

