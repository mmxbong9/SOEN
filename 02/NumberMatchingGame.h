#pragma once

#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))

namespace SOEN
{
	void NumberMatchingGame();
}
