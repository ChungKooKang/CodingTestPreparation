#include <iostream>
#include "Fibonacci.h"
#include "MoveCaseCalculation.h"
int main()
{
	history h;

	MoveCaseCalculation moveCase;
	std::cout << moveCase.FindWays(3,3 ) << std::endl;
}