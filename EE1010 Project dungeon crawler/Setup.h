#pragma once

#include "Room.h"
#include "Items.h"

// if time allows make this random generation instead of hard coded
// as its a template it needs to be in the header file

template <int t_rows, int t_columns> // function template to allow any size arrays to be passed
void setup2DArray(int rows, int columns, Room(&outArray)[t_rows][t_columns], Room** currentRoom)
{
	// setup rooms
	outArray[0][0] = Room("keyRoom", "A key sits in the middle of the room", "You see a key that you can pickup in the middle of the room");
	outArray[0][1] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[0][3] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[0][4] = Room("monsterBetterShieldRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[0][5] = Room("endMonsterRoom", "A huge monster sits in the middle of the room", "You see a huge monster that you can fight in the middle of the room, guarding the exit to the maze", "You hear a growling coming from this room, but the gate is locked");
	outArray[1][0] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[1][1] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[1][2] = Room("monsterBetterSwordRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[1][3] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[1][5] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[1][6] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[2][0] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[2][1] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[2][3] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[2][4] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[2][5] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[3][0] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[3][3] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[3][5] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[3][6] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[4][0] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[4][1] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[4][3] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[4][4] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[4][5] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[5][0] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");
	outArray[5][1] = Room("shieldRoom", "A shield sits in the middle of the room", "You see a sheild in the room, seemly abandonded, that you can pickup");
	outArray[5][2] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room", "A low grumble comes from this room");
	outArray[5][3] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[5][4] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[5][5] = Room("emptyRoom", "", "An empty room that you can pass freely through");
	outArray[6][3] = Room("startRoom", "You wake up in a what seems to be a maze, with cold stone walls all around apart from a single open door", "You see an open door that you can travel through", "It feels like you came from here");
	outArray[6][5] = Room("swordRoom", "A sword sits in the middle of the room", "You see a sword in the room, shining in the light, that you can pickup");
	outArray[6][6] = Room("monsterRoom", "A monster sits in the middle of the room", "You see a monster that you can fight in the middle of the room");

	// setup items
	Item key{};
	key.type = ItemType::KEY;
	key.name = "Key";
	key.keyType = KeyType::END_GATE;
	outArray[0][0].setItem(key);

	Item sword{};
	sword.type = ItemType::SWORD;
	sword.name = "Sword";
	sword.attack = 25;
	outArray[6][5].setItem(sword);

	Item shield{};
	shield.type = ItemType::SHIELD;
	shield.name = "Shield";
	shield.defense = 10;
	outArray[5][1].setItem(shield);

	Item betterShield{};
	betterShield.type = ItemType::SHIELD;
	betterShield.name = "Stronger Shield";
	betterShield.defense = 15;
	outArray[0][4].setItem(betterShield);

	Item betterSword{};
	betterSword.type = ItemType::SWORD;
	betterSword.name = "Bigger Sword";
	betterSword.attack = 60;
	outArray[1][2].setItem(betterSword);

	// setup monsters
	static Monster monster52 = Monster(25, 10, 5, 10, &outArray[5][2]);
	monster52.setHealth(25);
	monster52.setAlive(true);
	outArray[5][2].setMonster(&monster52);

	static Monster monster66 = Monster(25, 10, 5, 10, &outArray[6][6]);
	monster66.setHealth(25);
	monster66.setAlive(true);
	outArray[6][6].setMonster(&monster66);

	static Monster monster50 = Monster(40, 15, 10, 10, &outArray[5][0]);
	monster50.setHealth(40);
	monster50.setAlive(true);
	outArray[5][0].setMonster(&monster50);

	static Monster monster40 = Monster(40, 15, 10, 10, &outArray[4][0]);
	monster40.setHealth(40);
	monster40.setAlive(true);
	outArray[4][0].setMonster(&monster40);

	static Monster monster33 = Monster(40, 15, 10, 10, &outArray[3][3]);
	monster33.setHealth(40);
	monster33.setAlive(true);
	outArray[3][3].setMonster(&monster33);

	static Monster monster24 = Monster(40, 15, 10, 10, &outArray[2][4]);
	monster24.setHealth(40);
	monster24.setAlive(true);
	outArray[2][4].setMonster(&monster24);

	static Monster monster44 = Monster(50, 15, 15, 15, &outArray[4][4]);
	monster44.setHealth(50);
	monster44.setAlive(true);
	outArray[4][4].setMonster(&monster44);

	static Monster monster20 = Monster(50, 15, 15, 15, &outArray[2][0]);
	monster20.setHealth(50);
	monster20.setAlive(true);
	outArray[2][0].setMonster(&monster20);

	static Monster monster10 = Monster(50, 15, 15, 15, &outArray[1][0]);
	monster10.setHealth(50);
	monster10.setAlive(true);
	outArray[1][0].setMonster(&monster10);

	static Monster monster12 = Monster(50, 15, 15, 15, &outArray[1][2]);
	monster12.setHealth(50);
	monster12.setAlive(true);
	outArray[1][2].setMonster(&monster12);

	static Monster monster03 = Monster(50, 15, 15, 15, &outArray[0][3]);
	monster03.setHealth(50);
	monster03.setAlive(true);
	outArray[0][3].setMonster(&monster03);

	static Monster monster04 = Monster(50, 15, 15, 15, &outArray[0][4]);
	monster04.setHealth(50);
	monster04.setAlive(true);
	outArray[0][4].setMonster(&monster04);

	static Monster monster01 = Monster(70, 20, 15, 15, &outArray[0][1]);
	monster01.setHealth(70);
	monster01.setAlive(true);
	outArray[0][1].setMonster(&monster01);

	static Monster monster45 = Monster(70, 20, 15, 15, &outArray[4][5]);
	monster45.setHealth(70);
	monster45.setAlive(true);
	outArray[4][5].setMonster(&monster45);

	static Monster monster36 = Monster(70, 20, 15, 15, &outArray[3][6]);
	monster36.setHealth(70);
	monster36.setAlive(true);
	outArray[3][6].setMonster(&monster36);

	static Monster monster25 = Monster(70, 20, 15, 15, &outArray[2][5]);
	monster25.setHealth(70);
	monster25.setAlive(true);
	outArray[2][5].setMonster(&monster25);

	static Monster monster16 = Monster(70, 20, 15, 15, &outArray[1][6]);
	monster16.setHealth(70);
	monster16.setAlive(true);
	outArray[1][6].setMonster(&monster16);

	static Monster monster05 = Monster(99, 25, 25, 20, &outArray[0][5]);
	monster05.setHealth(99);
	monster05.setAlive(true);
	outArray[0][5].setMonster(&monster05);

	// setup room connections
	outArray[0][0].setEastRoom(&outArray[0][1]);

	outArray[0][1].setWestRoom(&outArray[0][0]);
	outArray[0][1].setSouthRoom(&outArray[1][1]);

	outArray[0][3].setEastRoom(&outArray[0][4]);
	outArray[0][3].setSouthRoom(&outArray[1][3]);

	outArray[0][4].setWestRoom(&outArray[0][3]);

	outArray[0][5].setSouthRoom(&outArray[1][5]);

	outArray[1][0].setEastRoom(&outArray[1][1]);
	outArray[1][0].setSouthRoom(&outArray[2][0]);

	outArray[1][1].setWestRoom(&outArray[1][0]);
	outArray[1][1].setSouthRoom(&outArray[2][1]);
	outArray[1][1].setNorthRoom(&outArray[0][1]);

	outArray[1][2].setEastRoom(&outArray[1][3]);

	outArray[1][3].setWestRoom(&outArray[1][2]);
	outArray[1][3].setSouthRoom(&outArray[2][3]);
	outArray[1][3].setNorthRoom(&outArray[0][3]);

	outArray[1][5].setSouthRoom(&outArray[2][5]);
	outArray[1][5].setNorthRoom(&outArray[0][5]);
	outArray[1][5].setEastRoom(&outArray[1][6]);

	outArray[1][6].setWestRoom(&outArray[1][5]);

	outArray[2][0].setEastRoom(&outArray[2][1]);
	outArray[2][0].setSouthRoom(&outArray[3][0]);
	outArray[2][0].setNorthRoom(&outArray[1][0]);

	outArray[2][1].setWestRoom(&outArray[2][0]);
	outArray[2][1].setNorthRoom(&outArray[1][1]);

	outArray[2][3].setEastRoom(&outArray[2][4]);
	outArray[2][3].setSouthRoom(&outArray[3][3]);
	outArray[2][3].setNorthRoom(&outArray[1][3]);

	outArray[2][4].setWestRoom(&outArray[2][3]);

	outArray[2][5].setSouthRoom(&outArray[3][5]);
	outArray[2][5].setNorthRoom(&outArray[1][5]);

	outArray[3][0].setNorthRoom(&outArray[2][0]);
	outArray[3][0].setSouthRoom(&outArray[4][0]);

	outArray[3][3].setNorthRoom(&outArray[2][3]);
	outArray[3][3].setSouthRoom(&outArray[4][3]);

	outArray[3][5].setNorthRoom(&outArray[2][5]);
	outArray[3][5].setSouthRoom(&outArray[4][5]);
	outArray[3][5].setEastRoom(&outArray[3][6]);

	outArray[3][6].setWestRoom(&outArray[3][5]);

	outArray[4][0].setNorthRoom(&outArray[3][0]);
	outArray[4][0].setSouthRoom(&outArray[5][0]);
	outArray[4][0].setEastRoom(&outArray[4][1]);

	outArray[4][1].setWestRoom(&outArray[4][0]);
	outArray[4][1].setSouthRoom(&outArray[5][1]);

	outArray[4][3].setNorthRoom(&outArray[3][3]);
	outArray[4][3].setSouthRoom(&outArray[5][3]);
	outArray[4][3].setEastRoom(&outArray[4][4]);

	outArray[4][4].setWestRoom(&outArray[4][3]);
	outArray[4][4].setSouthRoom(&outArray[5][4]);
	outArray[4][4].setEastRoom(&outArray[4][5]);

	outArray[4][5].setWestRoom(&outArray[4][4]);
	outArray[4][5].setNorthRoom(&outArray[3][5]);
	outArray[4][5].setSouthRoom(&outArray[5][5]);

	outArray[5][0].setNorthRoom(&outArray[4][0]);

	outArray[5][1].setNorthRoom(&outArray[4][1]);
	outArray[5][1].setEastRoom(&outArray[5][2]);

	outArray[5][2].setWestRoom(&outArray[5][1]);
	outArray[5][2].setEastRoom(&outArray[5][3]);

	outArray[5][3].setWestRoom(&outArray[5][2]);
	outArray[5][3].setSouthRoom(&outArray[6][3]);
	outArray[5][3].setEastRoom(&outArray[5][4]);
	outArray[5][3].setNorthRoom(&outArray[4][3]);

	outArray[5][4].setWestRoom(&outArray[5][3]);
	outArray[5][4].setEastRoom(&outArray[5][5]);
	outArray[5][4].setNorthRoom(&outArray[4][4]);

	outArray[5][5].setWestRoom(&outArray[5][4]);
	outArray[5][5].setNorthRoom(&outArray[4][5]);
	outArray[5][5].setSouthRoom(&outArray[6][5]);

	outArray[6][3].setNorthRoom(&outArray[5][3]);

	outArray[6][5].setNorthRoom(&outArray[5][5]);
	outArray[6][5].setEastRoom(&outArray[6][6]);

	outArray[6][6].setWestRoom(&outArray[6][5]);

	*currentRoom = &outArray[6][3];
}
