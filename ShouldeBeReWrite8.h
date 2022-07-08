#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
using string_list = std::list<std::string>;
using result = std::list<string_list>;
result FindGenerate(const std::string target, const string_list& stringList)
{
	std::vector<result> table(target.length() + 1);

	// base case
	table[0] = result{ {} };

	for (int i = 0; i <= target.length(); i++)
	{
		if (table.size() > 0)
		{
			for (auto e : stringList)
			{
				if (target.substr(i, e.length()) == e)
				{
					if (i + e.length() <= target.length())
					{
						for (auto e2 : table[i])
						{
							e2.push_back(e);
							table[i + e.length()].push_back(e2);
						}
					}
				}
			}
		}
	}

	return table[target.length()];
}

void Print(const result& r)
{
	std::cout << "{" << std::endl;

	for (auto e1 : r)
	{
		std::cout << "\t{";
		for (auto e2 : e1)
		{
			std::cout << e2 << ", ";
		}
		std::cout << "}" << std::endl;
	}

	std::cout << "}" << std::endl;
}