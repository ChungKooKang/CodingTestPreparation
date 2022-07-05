#include <iostream>
#include <string>
#include <vector>
#include <map>

// 주어진 문자열의 배열 stringlist의 원소들로 target 문자열을 만들 수 있는 지 : Desition
// 단 동일한 원소를 여러번 사용해도 됩니다.
// target이 ""인 경우는 무조건 참입니다.

// "abcd"
// { "a", "b", "c", "d" }

// "abcdef"
// { "ab", "abc", "cd", "def", "abcd"}

using history = std::map<std::string, bool>;


bool CanGenerate(std::string target, const std::vector<std::string>& stringlist, history& h)
{
	// solved?
	if (h.count(target) == 1)
	{
		return h[target];
	}


	//base case
	if (target == "")
	{
		return true;
	}

	// recursive case
	for (auto e : stringlist)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			if (CanGenerate(subs, stringlist, h))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	history h;
	std::cout << CanGenerate("abcd", { "a", "b", "c" , "d" }, h) << std::endl;
	h.clear();
	std::cout << CanGenerate("abcdef", { "ab", "abc", "cd", "def", "abcd" }, h) << std::endl;
}