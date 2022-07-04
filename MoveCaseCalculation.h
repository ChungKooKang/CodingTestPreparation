#pragma once
#include <map>

using moveCaseContainer = std::map<int, std::pair <int, int>>;

class MoveCaseCalculation
{

public :
	int FindWays(int m, int n, moveCaseContainer* c);
};

