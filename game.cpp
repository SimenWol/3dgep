#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	Sprite theSprite(new Surface("assets/ball.png"), 1);

	float spriteY = 0, speed = 1;
	void Game::Tick(float deltaTime)
	{
		printf("%f\n", deltaTime);

		screen->Clear(0);
		spriteY += speed;
		speed += 1.0f;

		if (spriteY > (512 - 50))
		{
			spriteY = 512 - 50;
			speed = -speed * 0.8f;
		}

		theSprite.Draw(screen, 20, (int)spriteY);
	}
};