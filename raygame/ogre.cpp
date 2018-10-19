#include "ogre.h"
#include "raylib.h"
#include <iostream>
#include <string>

void ogre::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}

ogre::ogre(const std::string & fileName)
{
	std::cout << "Creating sprite!" << std::endl;
	mySprite = LoadTexture(fileName.c_str());
}

ogre::~ogre()
{
	std::cout << "Destroying sprite!" << std::endl;
	UnloadTexture(mySprite);
}

bool ogre::follow(const Vector2 & dest)
{
	return false;
}