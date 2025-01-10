#pragma once

#include <string>

enum class ItemType
{
	NONE,
	KEY,
	SWORD,
	SHIELD
};

enum class KeyType
{
	NONE,
	END_GATE
};

struct Item
{
	ItemType type{ ItemType::NONE };
	std::string name{};
	float defense{};
	float attack{};
	KeyType keyType{};
};

