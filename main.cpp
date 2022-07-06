#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

// using solution = std::list<std::list<std::string>>;

// {} 
// solution x;

// {{}} 
// solution x { {} };

using result = std::list<std::list<std::string>>;
using history = std::map<std::string, result>;

result FindGenerate(std::string target, const std::vector<std::string>& stringList, history& h)
{
	// solved?
	if (h.count(target) == 1)
	{
		return h[target];
	}
	//base case
	if (target == "")
	{
		return result{ {} };
	}


	//recursive case

	result r;				// {};

	for (auto e : stringList)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			auto ret = FindGenerate(subs, stringList, h);

			for (auto e2 : ret)
			{
				e2.push_front(e);
				r.push_front(e2);
			}
		}
	}
	h[target] = r;
	return r;
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
		std::cout << "}, " << std::endl;
	}

	std::cout << "}" << std::endl;
}
int main()
{
	history h;
	Print(FindGenerate("abcdef", { "ab", "abc", "cd", "def","abcd", "c", "ef"}, h));
}