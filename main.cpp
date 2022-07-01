#include <iostream>
#include "Fibonacci.h"

int main()
{
	history h;

	Fibonacci f;
	std::cout << f.Do(50, h) << std::endl;
}