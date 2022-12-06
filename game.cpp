#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf

namespace Tmpl8
{
	static constexpr Pixel RED = 0xff0000;
	static constexpr Pixel GREEN = 0x00ff00;
	static constexpr Pixel BLUE = 0x0000ff;
	static constexpr Pixel YELLOW = 0xffff00;

	struct Line
	{
		vec2 p0, p1; // Begin & end line points.
		Pixel c;	 // Line colour
	};

	const Line text[] = {
		{ {240, 60},  {160, 60},  RED },    // Letter C
		{ {160, 60},  {80, 120},  RED },
		{ {80, 120},  {80, 180},  RED },
		{ {80, 180},  {160, 240}, RED },
		{ {160, 240}, {240, 240}, RED },
		{ {400, 60},  {320, 120}, GREEN },  // Letter O
		{ {320, 120}, {320, 180}, GREEN },
		{ {320, 180}, {400, 240}, GREEN },
		{ {400, 240}, {480, 240}, GREEN },
		{ {480, 240}, {560, 180}, GREEN },
		{ {560, 180}, {560, 120}, GREEN },
		{ {560, 120}, {480, 60},  GREEN },
		{ {480, 60},  {400, 60},  GREEN },
		{ {400, 120}, {400, 180}, GREEN },
		{ {400, 180}, {480, 180}, GREEN },
		{ {480, 180}, {480, 120}, GREEN },
		{ {480, 120}, {400, 120}, GREEN },
		{ {80, 300},  {80, 480},  BLUE },   // Letter D
		{ {80, 480},  {160, 480}, BLUE },
		{ {160, 480}, {240, 420}, BLUE },
		{ {240, 420}, {240, 360}, BLUE },
		{ {240, 360}, {160, 300}, BLUE },
		{ {160, 300}, {80, 300},  BLUE },
		{ {160, 360}, {160, 420}, BLUE },
		{ {480, 300}, {320, 300}, YELLOW }, // Letter E
		{ {320, 300}, {320, 480}, YELLOW },
		{ {320, 480}, {480, 480}, YELLOW },
		{ {320, 420}, {400, 420}, YELLOW }
	};

	void Game::Init() {}
	void Game::Shutdown() {}

	void Game::Tick(float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);

		for (auto& line : text) {
			screen->Line(line.p0.x, line.p0.y, line.p1.x, line.p1.y, line.c);
		}
	}
};