#pragma once

class Room;

class Monster
{
private:
	int health;
	int maxHealth;
	float attack;
	float defense;
	float dodgeChance;
	bool isAlive;

	Room* room;

public:
	Monster();
	Monster(int health, float attack, float defense, float dodgeChance, Room* room);

	void attackMonster(int& health, float playerAttack, float playerDefense, float playerDodgeChance);

	bool getIsAlive() const { return isAlive; }

	int getHealth() { return health; }
	int getMaxHealth() { return maxHealth; }
};