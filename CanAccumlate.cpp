#include "CanAccumlate.h"

bool CanAccumlate::Function(int sum, const std::vector<int>& numbers, History& h)
{
	//solved?
	if (h.count(sum) == 1)
	{
		return h[sum];
	}

	// base case
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	// recursive case
	for (auto e : numbers)
	{
		int remain = sum - e;
		if (Function(remain, numbers, h))
		{
			h[sum] = true;
			return true;
		}
	}

	h[sum] = false;
	return false;
}
