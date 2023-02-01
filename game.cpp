#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	void Game::Init() {}
	
	void Game::Shutdown() {}

	void Game::DrawBigDot(int loc_in)
	{
		Pixel* address = screen->GetBuffer();

		address[loc_in - 1 - 1600] = 0x00ff00;
		address[loc_in - 1600] = 0x00ff00;
		address[loc_in + 1 - 1600] = 0x00ff00;

		address[loc_in - 1 - 800] = 0x00ff00;
		address[loc_in - 800] = 0x00ff00;
		address[loc_in + 1 - 800] = 0x00ff00;

		address[loc_in - 1] = 0x00ff00;
		address[loc_in] = 0x00ff00;
		address[loc_in + 1] = 0x00ff00;
	}

	static Sprite noise(new Surface("assets/noise.png"), 1);
	int PixelX = 400, PixelY = 10;
	bool isWhite;

	// Screen: 800 x 512 pixels
	void Game::Tick(float deltaTime)
	{
		screen->Clear(0);
		noise.Draw(screen, 0, 0);
		
		Pixel* address = screen->GetBuffer();
		int loc = PixelX + PixelY * 800;
		int nextLoc = loc + 800;
		if (address[nextLoc] == 0) { isWhite = false; }
		else { isWhite = true; }

		Game::DrawBigDot(loc);

		if (PixelY > 510) PixelY = 10;
		if (!isWhite) PixelY += 1;
		else if (PixelY % 2 == 0) { PixelX += 1; }
		else if (PixelY % 2 == 1) { PixelX -= 1; }

	}
};