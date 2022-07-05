#include <iostream>
#include <vector>
#include <map>

using int_vector = std::vector<int>;
using history = std::map<int, std::shared_ptr<int_vector>>;

std::shared_ptr<int_vector> HowAccumulate(
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
	for (auto e : numbers)
	{
		int remain = sum - e;

		auto result = HowAccumulate(remain, numbers, h);

		if (result != nullptr)
		{
			result->push_back(e);
			(*h)[sum] = result;
			return (*h)[sum];
		}
	}

	(*h)[sum] = nullptr;

	return nullptr;
}

void Print(std::shared_ptr<int_vector> result)
{
	std::cout << "{";

	if (result != nullptr)
	{
		for (auto e : *result)
		{
			std::cout << e << " ";
		}
	}

	std::cout << "}" << std::endl;
}

int main()
{
	Print(HowAccumulate(8, { 2, 3, 5 }, std::make_shared<history>()));
	Print(HowAccumulate(7, { 1, 4 }, std::make_shared<history>()));
	Print(HowAccumulate(1000, { 7, 14 }, std::make_shared<history>()));
}