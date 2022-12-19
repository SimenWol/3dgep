#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf

namespace Tmpl8
{
	void Game::Init() {}
	void Game::Shutdown() {}

	Sprite theSprite(new Surface("assets/ball.png"), 1);
	int spriteX = 0;
	int spriteY = 100;
	int speedY = 1;
	int speedX = 3;
	int nBottomHits = 0;

	void Game::Tick(float deltaTime)
	{
		spriteY += speedY;
		speedY += 1;
		spriteX += speedX;

		const bool hitBottom = spriteY > ScreenHeight - theSprite.GetHeight();
		printf("hitBottom: %i\n", hitBottom);

		if (spriteX + theSprite.GetWidth() > ScreenWidth || spriteX < 0)
		{
			speedX *= -1;
		}

		if (nBottomHits < 50 && spriteY > ScreenHeight - theSprite.GetHeight())
		{
			spriteY = ScreenHeight - theSprite.GetHeight();
			speedY = -(speedY - 2);
			screen->Clear(0xff0000);
			nBottomHits++;
		}
		else
		{
			screen->Clear(0);
		}
		theSprite.Draw(screen, spriteX, spriteY);


	}
};