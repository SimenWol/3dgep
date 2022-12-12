#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
    void Game::Init()
    {
        x = 100;
        y = 0;
    }
    void Game::Shutdown() {}

    void Game::DrawI(int x_in, int y_in)
    {
        screen->Line(100 + x_in, 50 + y_in, 200 + x_in, 50 + y_in, 0xffffff);
        screen->Line(150 + x_in, 50 + y_in, 150 + x_in, 300 + y_in, 0xffffff);
        screen->Line(100 + x_in, 300 + y_in, 200 + x_in, 300 + y_in, 0xffffff);
    }

    void Game::DrawFatI(int x_in, int y_in)
    {
        DrawI(x_in, y_in);
        DrawI(x_in + 1, y_in);
        DrawI(x_in, y_in + 1);
        DrawI(x_in + 1, y_in + 1);
    }

    void Game::Tick(float deltaTime)
    {
        screen->Clear(80);
        DrawFatI(x, y);

        if (movingRight) x++;
        else x--;
        if (x >= 500) movingRight = false;
        if (x <= 100) movingRight = true;
    }
};