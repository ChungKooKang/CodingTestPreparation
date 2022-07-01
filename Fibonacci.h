#pragma once
#include <map>

using history = std::map<int, int64_t>;

class Fibonacci
{

public :
	int64_t Do(int n, history& h);
};

