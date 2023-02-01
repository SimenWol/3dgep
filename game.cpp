#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	void Game::Init() {}
	
	void Game::Shutdown() {}

	// Screen: 800 x 512 pixels
	void Game::Tick(float deltaTime)
	{
		Pixel* address = screen->GetBuffer();

		for (int i = 0; i < (400 + 400 * 800); i++)
		{
			if (i % 2 == 0) address[i] = 0xffffff;
			else address[i] = 0x000000;
		}
	}
};