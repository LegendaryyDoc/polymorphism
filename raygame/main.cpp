#include "raylib.h"
#include "player.h"
#include "picker.h"'
#include "wizard.h"
#include "imp.h"
#include "ogre.h"
#include "necromancer.h"
#include "enemy.h"
#include "barbarian.h"
#include <iostream>

int main()
{
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	picker wiz("wizzard_f_idle_anim_f0.png", {200,200});
	picker bar("knight_f_idle_anim_f0.png", {500, 200});

	wizard urawizard("wizzard_f_idle_anim_f0.png");
	barb ogh("knight_f_idle_anim_f0.png");
	
	/*imp i("imp_idle_anim_f0.png");
	ogre o("ogre_idle_anim_f0.png");
	necromancer n("necromancer_idle_anim_f0.png");*/

	player * pl = nullptr;
	
	enemy * en[10];

	en[0] = new necromancer("necromancer_idle_anim_f0.png");
	en[1] = new imp("imp_idle_anim_f0.png");
	en[2] = new imp("imp_idle_anim_f0.png");
	en[3] = new imp("imp_idle_anim_f0.png");
	en[4] = new ogre("ogre_idle_anim_f0.png");
	en[5] = new ogre("ogre_idle_anim_f0.png");
	en[6] = new ogre("ogre_idle_anim_f0.png");
	en[7] = new imp("imp_idle_anim_f0.png");
	en[8] = new imp("imp_idle_anim_f0.png");
	en[9] = new necromancer("necromancer_idle_anim_f0.png");


	bool waitingForChoice = true;
	while (waitingForChoice)
	{
		wiz.CheckForClick();
		if (wiz.CheckForClick())
		{
			pl = &urawizard;
			pl->enabled = true;
			waitingForChoice = false;
		}

		bar.CheckForClick();
		if (bar.CheckForClick())
		{
			pl = &ogh;
			pl->enabled = true;
			waitingForChoice = false;
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);
		//Do Menu UI Screen here

		DrawText("Choose a character!", 250, 100, 20, MAROON);

		wiz.draw();
		wiz.position = { 200, 200 };

		bar.draw();
		bar.position = { 500, 200 };

		EndDrawing();
	}

	/*-----------------------------------------------------------*/

	while (!WindowShouldClose())
	{
		Vector2 cursor = GetMousePosition();

		pl->moveTo({cursor.x, cursor.y});

		BeginDrawing();

		ClearBackground(RAYWHITE);

		pl->draw();

		EndDrawing();
	}
	CloseWindow();       

	return 0;
}