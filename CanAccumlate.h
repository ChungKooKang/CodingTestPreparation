#pragma once
#include <map>
#include <vector>
// ������ �迭 numbers���� �� ���ҵ��� �����Ͽ� sum�� ����� �� �� �ִ��� Ȯ���ϴ� �Լ�
// �� numbers�� ����� �迭
// sum�� ����� ���ؼ��� ������ ���Ҹ� ������ ����ص� ����


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

