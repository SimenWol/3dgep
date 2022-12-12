#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	void Game::Init() {}
	void Game::Shutdown() {}

	Sprite theSprite(new Surface("assets/ctankbase.tga"), 16);

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 16; x++)
            {
                theSprite.SetFrame(x);
                theSprite.Draw(screen, x * 50, y * 50);
            }
        }
    }
};