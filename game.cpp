#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <utility>

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

	float spriteY = 0.0f, speed = 1.0f;
	void Game::Tick(float deltaTime)
	{
		const float screenHeight = static_cast<float>(screen->GetHeight());
		const float screenWidth = static_cast<float>(screen->GetWidth());

		// Multiply DeltaTime by 0.001 to get deltaTime in seconds
		// By using std::min, you prevent long pauses messing up the physics
		deltaTime = std::min(deltaTime * 0.001f, 0.05f);
		printf("%f\n", deltaTime);

		screen->Clear(0);
		spriteY += speed * deltaTime;
		speed += 1000.0f * deltaTime;

		if (spriteY > (screenHeight - static_cast<float>(theSprite.GetHeight())))
		{
			spriteY = (screenHeight - static_cast<float>(theSprite.GetHeight()));
			speed = -speed * 0.8f; // dampening and inverting
		}

		theSprite.Draw(screen, 20, static_cast<int>(spriteY));
	}
};