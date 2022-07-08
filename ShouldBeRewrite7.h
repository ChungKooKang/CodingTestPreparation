#pragma once
#include <iostream>
#include <string>
#include <vector>

// "abcdef" { "ab" , "abc", "cd", "def", "abcd", "ef"}

using string_vector = std::vector < std::string>;

bool CanGenerate(const std::string target, const string_vector& stringList)
{
	// table
	std::vector<bool> table(target.length() + 1, false);

	// base case
	table[0] = true;

	for (int i = 0; i <= target.length(); ++i)
	{
		if (table[i] == true)
		{
			for (auto e : stringList)
			{
				if (target.substr(i, e.length()) == e)
				{
					if (i + e.length() <= target.length())
					{
						table[i + e.length()] = true;
					}
				}
			}
		}
	}
	return table[target.length()];
}

int HowManyGenerate(const std::string target, const string_vector& strinList)
{
	// table
	std::vector<int> table(target.length() + 1, 0);

	// base case
	table[0] = 1;

	for (int i = 0; i <= target.length(); i++)
	{
		if (table[i] > 0)
		{
			for (auto e : strinList)
			{
				if (target.substr(i, e.length()) == e)
				{
					if (i + e.length() <= target.length())
					{
						table[i + e.length()] += table[i];
					}
				}
			}
		}
	}
	return table[target.length()];
}