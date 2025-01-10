#pragma once

class Room;

class Monster
{
private:
	int health;
	float attack;
	float defense;
	float dodgeChance;
	float damage;
	bool isAlive;

	Room* room;

public:
	Monster();
	Monster(int health, float attack, float defense, float dodgeChance, float damage, Room* room);

	void attackMonster(int& health, float playerAttack, float playerDefense, float playerDodgeChance);

	bool getIsAlive() const { return isAlive; }
};