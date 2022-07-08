#pragma once
#include <iostream>
#include <vector>


// 피보나치 수열
// 이전 수와 그 앞의 수를 더함
// f(0) = 0
// f(1) = 1
// f(2) = f(0) + f(1) = 1
// f(3) = f(1) + f(2) = 2

int64_t Fibonacci(const int n)
{
	std::vector<int64_t> table(n + 1);

	// base case
	table[0] = 0;
	table[1] = 1;

	for (int i = 0; i <= n; ++i)
	{
		if (i + 2 <= n)
		{
			table[i + 2] += table[i];

		}
		if (i + 1 <= n)
		{
			table[i + 1] += table[i];
		}
	}

	return table[n];
	// recursive case

}

int FindWays(int m, int n)
{

	std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));

	// base case
	table[1][1] = 1;

	for (int row = 0; row <= m; ++row)
	{
		for (int col = 0; col <= n; ++col)
		{
			if (row + 1 <= m)
			{
				table[row + 1][col] += table[row][col];

			}
			if (col + 1 <= n)
			{
				table[row][col + 1] += table[row][col];
			}
		}
	}

	return table[m][n];
}

using int_vector = std::vector<int>;

bool CanAccum(int sum, const int_vector& numbers)
{
	std::vector<bool> table(sum + 1);

	// base case
	table[0] = true;

	for (int i = 0; i <= sum; i++)
	{
		if (table[i] == true)
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					table[i + e] = true;
				}
			}
		}
	}
	return table[sum];
}

std::shared_ptr<int_vector>HowAccumulate(int sum, const int_vector& numbers)
{
	std::vector<std::shared_ptr<int_vector>> table(sum + 1, nullptr);

	// base case
	table[0] = std::make_shared<int_vector>(0);

	for (int i = 0; i <= sum; i++)
	{
		if (table[i] != nullptr)
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					table[i + e] = std::make_shared<int_vector>(*table[i]);	// 복사 생성자 deep copy
					table[i + e]->push_back(e);
				}
			}
		}
	}

	return table[sum];
}

std::shared_ptr<int_vector> BestAccumulate(int sum, const int_vector& numbers)
{
	std::vector<std::shared_ptr<int_vector>> table(sum + 1, nullptr);

	// base case
	table[0] = std::make_shared<int_vector>(0);

	for (int i = 0; i <= sum; i++)
	{
		if (table[i] != nullptr)
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					if (table[i + e] == nullptr || table[i + e]->size() > (table[i]->size() + 1))
					{
						table[i + e] = std::make_shared<int_vector>(*table[i]);
						table[i + e]->push_back(e);
					}
				}
			}
		}
	}

	return table[sum];
}
