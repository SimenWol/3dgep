#include "game.h"
#include "surface.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <math.h>

namespace Tmpl8
{
    void Game::Init() {}
    void Game::Shutdown() {}

    Sprite tank(new Surface("assets/ctankbase.tga"), 16);
    int px = 32, py = 32;

    Surface tiles("assets/nc2tiles.png");

    char map[5][40] = {
         "kcX kcX kcX kcX kcX kcX kcX kcX kcX kcX",
         "kcX fb- fb- fb- kcX kcX kcX kcX kcX kcX",
         "kcX fb- fb- fb- fb- fb- kcX kcX kcX kcX",
         "kcX lcX lcX fb- fb- fb- kcX kcX kcX kcX",
         "kcX kcX kcX lcX lcX lcX kcX kcX kcX kcX"
    };

    void DrawTile(int tx, int ty, Surface* screen, int x, int y)
    {
        Pixel* src = tiles.GetBuffer() + 1 + tx * 33 + (1 + ty * 33) * 595;
        Pixel* dst = screen->GetBuffer() + x + y * 800;
        for (int i = 0; i < 32; i++, src += 595, dst += 800)
        {
            for (int j = 0; j < 32; j++) { dst[j] = src[j]; }
        }
    }

    // Check if the player can move over the tile at pos x, y.
    bool CheckPos(int x, int y)
    {
        x += 10;
        y += 10;
        int tx = lround(x) / 32, ty = lround(y) / 32;
        return map[ty][tx * 4 + 2] != 'X';
    }


    int tankFrame = 0, tankFrameCooldown = 0;

    void Game::Tick(float deltaTime)
    {
        int topLeftX, topLeftY;
        topLeftX = screen->GetWidth() / 2 - 5 * 32;
        topLeftY = screen->GetHeight() / 2 - static_cast<int>(2.5 * 32);

        screen->Clear(0);
        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 10; x++)
            {
                int tx = map[y][x * 4] - 'a';
                int ty = map[y][x * 4 + 1] - 'a';
                DrawTile(tx, ty, screen, topLeftX + x * 32, topLeftY + y * 32);
            }

        tank.Draw(screen, px + topLeftX, py + topLeftY);

        int nx = px, ny = py;
        if (GetAsyncKeyState(VK_LEFT)) // 12
        {
            if (tankFrame != 12 && tankFrameCooldown == 0) {
                if (tankFrame == 0) { tankFrame = 15; }
                else if (tankFrame < 4 || tankFrame > 12) { tankFrame--; }
                else if (tankFrame >= 4 && tankFrame < 16) { tankFrame++; }

                tankFrameCooldown = 5;
            }

            nx--;
            tank.SetFrame(tankFrame);
        }
        if (GetAsyncKeyState(VK_RIGHT)) // 4
        {
            if (tankFrame != 4 && tankFrameCooldown == 0) {
                if (tankFrame == 15) { tankFrame = 0; }
                else if (tankFrame > 12 || tankFrame < 4) { tankFrame++; }
                else if (tankFrame > 4 && tankFrame <= 12) { tankFrame--; }

                tankFrameCooldown = 5;
            }

            nx++;
            tank.SetFrame(tankFrame);
        }
        if (GetAsyncKeyState(VK_UP)) // 0
        {
            if (tankFrame != 0 && tankFrameCooldown == 0) {
                if (tankFrame == 15) { tankFrame = 0; }
                else if (tankFrame > 8) { tankFrame++; }
                else if (tankFrame <= 8) { tankFrame--; }

                tankFrameCooldown = 5;
            }

            ny--;
            tank.SetFrame(tankFrame);
        }
        if (GetAsyncKeyState(VK_DOWN)) // 8
        {
            if (tankFrame != 8 && tankFrameCooldown == 0) {
                if (tankFrame < 8) { tankFrame++; }
                else if (tankFrame > 8) { tankFrame--; }

                tankFrameCooldown = 5;
            }

            ny++;
            tank.SetFrame(tankFrame);
        }

        if (CheckPos(nx, ny) && CheckPos(nx + 30, ny + 30) &&
            CheckPos(nx + 30, ny) && CheckPos(nx, ny + 30))
        {
            px = nx;
            py = ny;
        }

        if (tankFrameCooldown != 0) { tankFrameCooldown--; }
    }
};