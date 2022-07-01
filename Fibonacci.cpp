#include "Fibonacci.h"

int Fibonacci::Do(int n)
{
    // base case
    if (n <= 2)
    {
        return 1;
    }

    // recursive case
    return Do(n - 1) + Do(n - 2);

}
