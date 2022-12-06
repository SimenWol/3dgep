#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf

namespace Tmpl8
{

	struct linepoints {
		int x1;
		int y1;
		int x2;
		int y2;
		int color;
	};
	linepoints codewordArray[28];

	void Game::Init()
	{
		// letter C (red)
		codewordArray[0] = { 240, 60, 160, 60, 0xff0000 };
		codewordArray[1] = { 160, 60, 80, 120, 0xff0000 };
		codewordArray[2] = { 80, 120, 80, 180, 0xff0000 };
		codewordArray[3] = { 80, 180, 160, 240, 0xff0000 };
		codewordArray[4] = { 160, 240, 240, 240, 0xff0000 };

		// letter O (green)
		codewordArray[5] = { 400, 60, 320, 120, 0x00ff00 };
		codewordArray[6] = { 320, 120, 320, 180, 0x00ff00 };
		codewordArray[7] = { 320, 180, 400, 240, 0x00ff00 };
		codewordArray[8] = { 400, 240, 480, 240, 0x00ff00 };
		codewordArray[9] = { 480, 240, 560, 180, 0x00ff00 };
		codewordArray[10] = { 560, 180, 560, 120, 0x00ff00 };
		codewordArray[11] = { 560, 120, 480, 60, 0x00ff00 };
		codewordArray[12] = { 480, 60, 400, 60, 0x00ff00 };
		codewordArray[13] = { 400, 120, 400, 180, 0x00ff00 };
		codewordArray[14] = { 400, 180, 480, 180, 0x00ff00 };
		codewordArray[15] = { 480, 180, 480, 120, 0x00ff00 };
		codewordArray[16] = { 480, 120, 400, 120, 0x00ff00 };

		// letter D (blue)
		codewordArray[17] = { 80, 300, 80, 480, 0x0000ff };
		codewordArray[18] = { 80, 480, 160, 480, 0x0000ff };
		codewordArray[19] = { 160, 480, 240, 420, 0x0000ff };
		codewordArray[20] = { 240, 420, 240, 360, 0x0000ff };
		codewordArray[21] = { 240, 360, 160, 300, 0x0000ff };
		codewordArray[22] = { 160, 300, 80, 300, 0x0000ff };
		codewordArray[23] = { 160, 360, 160, 420, 0x0000ff };

		// letter E (yellow)
		codewordArray[24] = { 480, 300, 320, 300, 0xffff00 };
		codewordArray[25] = { 320, 300, 320, 480, 0xffff00 };
		codewordArray[26] = { 320, 480, 480, 480, 0xffff00 };
		codewordArray[27] = { 320, 420, 400, 420, 0xffff00 };
	}

	void Game::Shutdown() {}

	void Game::Tick(float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);

		for (linepoints l : codewordArray) {
			screen->Line(l.x1, l.y1, l.x2, l.y2, l.color);
		}

		if (++frame == 36) frame = 0;
	}
};