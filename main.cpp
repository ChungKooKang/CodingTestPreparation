#include <iostream>
#include <vector>
#include "Fibonacci.h"
#include "MoveCaseCalculation.h"

// 정수의 배열 numbers에서 각 원소들을 조합하여 sum을 만들어 낼 수 있는지 확인하는 함수
// 단 numbers는 양수의 배열
// sum은 만들기 위해서는 동일한 원소를 여러번 사용해도 가능


// Ex)
// numbers {2, 3, 5 }
// sum 8
// => true (2, 2, 2, 2)




bool CanAccumulate(int sum,const std::vector<int>& numbers)
{
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
		if (CanAccumulate(remain, numbers))
		{
			return true;
		}
	}

	return false;
}
int main()
{
	std::cout << CanAccumulate(8, { 2, 3, 5 }) << std::endl;
	std::cout << CanAccumulate(7, { 5, 3, 4, 7 }) << std::endl;
	std::cout << CanAccumulate(720, { 10, 50, 100, 500 }) << std::endl;
}