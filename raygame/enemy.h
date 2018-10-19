#pragma once
#include "raylib.h"
#include <iostream>
class enemy
{
public:
	bool enabled = false;

	Vector2 position = { 100,100 };
	float speed = 5.0f;
	Texture2D mySprite;
	bool virtual follow(const Vector2 &dest);
	enemy(const std::string & fileName);//assign the sprite image.
	enemy();
	~enemy();

	void virtual draw();
};