#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	void Game::Init() {}
	
	void Game::Shutdown() {}

	void Game::Tick(float deltaTime)
	{
		Pixel* address = screen->GetBuffer();

		for (int x = 0; x < 200; x++)
		{
			for (int y = 0; y < 200; y++)
			{
				if ((x % 2) == 1)
				{
					if ((y % 2) == 1) { address[x + y * 800] = 0xffffff; }
					else { address[x + y * 800] = 0x000000; }
				}
				else
				{
					if ((y % 20 == 0)) { address[x + y * 800] = 0xffffff; }
					else { address[x + y * 800] = 0x000000; }
				}
			}
		}

		for (int x = 200; x < 400; x++)
		{
			for (int y = 0; y < 200; y++) { address[x + y * 800] = 0x808080; }
		}
	}
};