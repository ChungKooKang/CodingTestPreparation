#pragma once
#include <iostream>
#include <vector>
#include <map>

// ������ �迭 numbers���� ���ڵ��� �����Ͽ� sum�� ����� �� �� �ִ� �ּ� ũ���� ������ ��ȯ
// �� , numbers�� ����̸� ������ ��ʼҸ� ������ ����ص� ��

using int_vector = std::vector<int>;
using history = std::map<int, std::shared_ptr<int_vector>>;

std::shared_ptr<int_vector> BestAccumulate(
	int sum,
	const int_vector& numbers,
	std::shared_ptr<history> h
)
{
	// solved ?
	if (h->count(sum) == 1)
	{
		return (*h)[sum];
	}

	// base case
	if (sum == 0)
	{
		return std::make_shared<int_vector>();
	}
	if (sum < 0)
	{
		return nullptr;
	}

	// recursive case
	std::shared_ptr<int_vector> best{ nullptr };
	for (auto e : numbers)
	{
		int remain = sum - e;
		auto ret = BestAccumulate(remain, numbers, h);

		if (ret != nullptr)
		{
			std::shared_ptr<int_vector> v = std::make_shared<int_vector>();
			v->resize(ret->size());
			std::copy(ret->begin(), ret->end(), v->begin());
			v->push_back(e);

			if (best == nullptr || v->size() < best->size())
			{
				best = v;
			}
		}
	}

	(*h)[sum] = best;
	return (*h)[sum];

}

void Print(std::shared_ptr<int_vector> r)
{
	std::cout << "{";

	if (r != nullptr)
	{
		for (auto e : *r)
		{
			std::cout << e << " ";
		}
	}

	std::cout << "}" << std::endl;
}
