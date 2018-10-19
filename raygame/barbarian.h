#pragma once
#include "player.h"
#include "raylib.h"

class barb : public player
{
public:
	bool enabled = false;

	Vector2 des = {100,100};

	void draw();
	bool moveTo(const Vector2 &dest);

	barb(const std::string & fileName);//assign the sprite image.
	~barb();
};
