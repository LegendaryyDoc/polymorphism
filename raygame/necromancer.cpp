#include "necromancer.h"
#include "raylib.h"
#include <iostream>
#include <string>

void necromancer::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}

necromancer::necromancer(const std::string & fileName)
{
	std::cout << "Creating sprite!" << std::endl;
	mySprite = LoadTexture(fileName.c_str());
}

necromancer::~necromancer()
{
	std::cout << "Destroying sprite!" << std::endl;
	UnloadTexture(mySprite);
}

bool necromancer::follow(const Vector2 & dest)
{
	return false;
}