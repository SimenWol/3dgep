#include "game.h"
#include "surface.h"
#include "windows.h"

namespace Tmpl8
{
    Surface tiles("assets/nc2tiles.png");
    Sprite tank(new Surface("assets/ctankbase.tga"), 16);
    int px = 0, py = 0;

    class Tank
    {
    public:
        Tank()
        {
            x = 0;
            y = 4 * 64;
            rotation = 0;
        }
        void Tank::Move(Surface* gameScreen)
        {
            x++;
            if (x > 800) x = 0;

            tank.Draw(gameScreen, x, y);
        }
        int x, y, rotation;
    };

    Tank mytank;

    void Game::Init() {}
    void Game::Shutdown() {}

    char map[5][30] = {
        "kc kc kc kc kc kc kc kc kc kc",
        "kc fb fb fb kc kc kc kc kc kc",
        "kc fb fb fb fb fb kc kc kc kc",
        "kc lc lc fb fb fb kc kc kc kc",
        "kc kc kc lc lc lc kc kc kc kc" };

    void DrawTile(int tx, int ty, Surface* screen, int x, int y)
    {
        Pixel* src = tiles.GetBuffer() + 1 + tx * 33 + (1 + ty * 33) * 595;
        Pixel* dst = screen->GetBuffer() + x + y * 800;
        for (int i = 0; i < 32; i++, src += 595, dst += 800)
            for (int j = 0; j < 32; j++)
                dst[j] = src[j];
    }

    void Game::Tick(float deltaTime)
    {
        // Clear the graphics window
        screen->Clear(0);


        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 10; x++)
            {
                int tx = map[y][x * 3] - 'a', ty = map[y][x * 3 + 1] - 'a';
                DrawTile(tx, ty, screen, x * 32, y * 32);
            }
        if (GetAsyncKeyState(VK_LEFT)) { px--; tank.SetFrame(12); }
        if (GetAsyncKeyState(VK_RIGHT)) { px++; tank.SetFrame(4); }
        if (GetAsyncKeyState(VK_UP)) { py--; tank.SetFrame(0); }
        if (GetAsyncKeyState(VK_DOWN)) { py++; tank.SetFrame(8); }

        mytank.Move(screen);
        tank.Draw(screen, px, py);
    }
};