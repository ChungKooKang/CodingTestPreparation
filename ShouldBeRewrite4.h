#pragma once
#include <string>
#include <vector>
#include <map>
// �־��� �迭 stringlist���� ���ҵ��� ������ target ���ڿ��� ���� �� �ִ� ��� ����� ��
// ������ ���Ҹ� ������ ��� ����
// target�� �� ���ڿ��� ���� �ƹ��͵� �������� ������ �ǹǷ� 1

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