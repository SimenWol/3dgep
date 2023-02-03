#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	static Sprite spectrum(new Surface("assets/spectrum.jpg"), 1);

	void Game::Init()
	{
		spectrum.Draw(screen, 0, 0);
	}
	
	void Game::Shutdown() {}

	void Game::Tick(float deltaTime)
	{
		Pixel* address = screen->GetBuffer();

		for (int x = 0; x < screen->GetWidth(); x++)
		{
			for (int y = 0; y < screen->GetHeight(); y++)
			{
				int locColor = address[x + y * 800];
				
				if (locColor != 0x000000)
				{
					int maskR = 255 << 16;
					int red = (locColor & maskR) >> 16;
					int maskG = 255 << 8;
					int green = (locColor & maskG) >> 8;
					int maskB = 255;
					int blue = locColor & maskB;

					if (red != 0) { red -= 1; }
					if (green != 0) { green -= 1; }
					if (blue != 0) { blue -= 1; }

					address[x + y * 800] = ((red << 16) + (green << 8) + blue);
				}
			}
		}
	}
};