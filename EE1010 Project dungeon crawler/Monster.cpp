#include "Monster.h"
#include "Room.h"
#include "Random.h"

#include <iostream>

Monster::Monster()
{
	health = 0;
	attack = 0;
	defense = 0;
	hitChance = 0;
	isAlive = false;
	room = nullptr;
}

Monster::Monster(float health, float attack, float defense, float dodgeChance, float damage, float hitChance, Room* room)
{
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->dodgeChance = dodgeChance;
	this->damage = damage;
	this->hitChance = hitChance;
	this->room = room;
	isAlive = true;
}

void Monster::attackMonster(float playerAttack, float playerDefense)
{
	if (isAlive)
	{
		float damage = generateRandomNumber(playerAttack, playerAttack*0.8) - defense;
		if (generateRandomNumber(0, 100) < dodgeChance)
		{
			std::cout << "The monster dodged your attack.\n";
			return;
		}
		if (damage < 0)
		{
			damage = 0;
		}
		health -= damage;
		if (health <= 0)
		{
			isAlive = false;
			std::cout << "The monster has been defeated.\n";
			room->setMonster(nullptr);
		}
		else
		{
			std::cout << "The monster has " << health << " health left.\n";
		}
	}
	else
	{
		std::cout << "The monster is already defeated.\n";
	}
}