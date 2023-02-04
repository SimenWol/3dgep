#include "game.h"
#include "surface.h"
#include "template.h"

namespace Tmpl8
{
    float x[4096], y[4096];

    void Game::Init()
    {
        for (int i = 0; i < 4096; i++)
        {
            x[i] = float(IRand(800)), y[i] = float(IRand(512));
        }
    }

    void Game::Shutdown() {}

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);

        for (int i = 0; i < 4096; i++)
        {
            float dx = x[i] - mousex, dy = y[i] - mousey;
            float dist = sqrtf(dx * dx + dy * dy);
            if (dist < 50)
                x[i] += dx / dist, y[i] += dy / dist;
            screen->Plot(x[i], y[i], 0xffffff);
        }
    }
};