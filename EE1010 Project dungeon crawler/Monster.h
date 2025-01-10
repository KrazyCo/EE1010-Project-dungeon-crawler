#pragma once

class Room;

class Monster
{
private:
	float health;
	float attack;
	float defense;
	float dodgeChance;
	float damage;
	float hitChance;
	bool isAlive;

	Room* room;

public:
	Monster();
	Monster(float health, float attack, float defense, float dodgeChance, float damage, float hitChance, Room* room);

	void attackMonster(float playerAttack, float playerDefense);

	bool getIsAlive() const { return isAlive; }
};