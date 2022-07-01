#include "MoveCaseCalculation.h"

int MoveCaseCalculation::FindWays(int m, int n, moveCaseContainer* c)
{
	// base case
	if (m == 1 && n == 1)
	{
		return 1;
	}
	if (m == 0 || n == 0)
	{
		return 0;
	}

	// recursive case

	return FindWays(m -1, n, c) + FindWays(m, n -1, c);
}
