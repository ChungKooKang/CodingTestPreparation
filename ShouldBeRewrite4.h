#pragma once
#include <string>
#include <vector>
#include <map>
// 주어진 배열 stringlist에서 원소들을 선택해 target 문자열을 만들 수 있는 모든 경우의 수
// 동일한 원소를 여러번 사용 가능
// target이 빈 문자열인 경우는 아무것도 선택하지 않으면 되므로 1

using string_vector = std::vector<std::string>;
using history = std::map<std::string, int>;

int CanGenerate(std::string target, const string_vector& stringList, history& h)
{
	// solved?
	if (h.count(target) == 1)
	{
		return h[target];
	}
	// base case
	if (target == "")
	{
		return 1;
	}

	// recursive case
	int count{};
	for (auto e : stringList)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			count += CanGenerate(subs, stringList, h);
		}
	}
	h[target] = count;
	return count;
}