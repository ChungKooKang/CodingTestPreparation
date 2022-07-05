#pragma once
#include <map>
#include <vector>
// 정수의 배열 numbers에서 각 원소들을 조합하여 sum을 만들어 낼 수 있는지 확인하는 함수
// 단 numbers는 양수의 배열
// sum은 만들기 위해서는 동일한 원소를 여러번 사용해도 가능


// Ex)
// numbers {2, 3, 5 }
// sum 8
// => true (2, 2, 2, 2)


using History = std::map<int, bool>;
class CanAccumlate
{
public :

	bool Function(int sum, const std::vector<int>& numbers, History& h);
};

