#include "Monster.h"
#include "Room.h"
#include "Random.h"

#include <iostream>

Monster::Monster()
{
	health = 0;
	maxHealth = 0;
	attack = 0;
	defense = 0;
	dodgeChance = 0;
	isAlive = false;
	room = nullptr;
}

Monster::Monster(int health, float attack, float defense, float dodgeChance, Room* room)
{
	this->health = health;
	this->maxHealth = health;
	this->attack = attack;
	this->defense = defense;
	this->dodgeChance = dodgeChance;
	this->room = room;
	isAlive = true;
}

void Monster::attackMonster(int& playerHealth, float playerAttack, float playerDefense, float playerDodgeChance)
{
	if (isAlive)
	{
		int playerHealthToHeal = static_cast<int>(maxHealth * 0.1);
		if (generateRandomNumber(0, 100) < dodgeChance)
		{
			room->printRoom();
			std::cout << "\nThe monster dodged your attack.\n";
		}
		else
		{
			int damage = generateRandomNumber(static_cast<int>(playerAttack), static_cast<int>(playerAttack * 0.8)) - static_cast<int>(defense);
			if (damage < 0)	damage = 0;
			this->health -= damage;
			if (health <= 0) 
			{ 
				isAlive = false;
				health = 0;
				if (room->getItem().type == ItemType::NONE)
				{
					room->setCenterText("A defeated monster lies in the middle of the room");
					room->setDescription("A faint smell of monster lingers in the air");
					room->setHint("");
				}
				else
				{
					room->setCenterText("A " + room->getItem().name + " sits in the middle of the room");
					room->setDescription("A faint smell of monster lingers in the air");
					room->setHint("");
				}
				playerHealth += playerHealthToHeal;
				if (playerHealth > 100) { playerHealth = 100; }
			}

			room->printRoom();

			std::cout << "\nYou dealt " << damage << " damage to the monster.\n";
			if (health > 0)
			{
				std::cout << "The monster has " << health << " health left.\n";
			}
		}
		if (health <= 0)
		{
			std::cout << "The monster has been defeated.\n";
			std::cout << "You use the remains of the monster to create a potion, healing you " << playerHealthToHeal << " health\n";
			if (room->getItem().type != ItemType::NONE)
			{
				std::cout << "As the dust settles, you see a " << room->getItem().name << " sitting in the room\n";
			}
		}
		else
		{
			if (generateRandomNumber(0, 100) < playerDodgeChance)
			{
				std::cout << "As the monster tries to strike back, you manage to dodge its attack";
			}
			else
			{
				int damage = generateRandomNumber(static_cast<int>(attack), static_cast<int>(attack * 0.8)) - static_cast<int>(playerDefense);
				if (damage < 0)	damage = 0;
				playerHealth -= damage;
				if (playerHealth < 0) { playerHealth = 0; }
				std::cout << "The monster dealt " << damage << " damage to you in retaliation.\n";
			}
		}
	}
	else
	{
		std::cout << "The monster is already defeated.\n";
	}
}