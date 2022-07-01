#include "Fibonacci.h"


int64_t Fibonacci::Do(int n, history& h)
{
    // solved?
    if ( h.count(n) == 1)
    {
        return h[n];
    }

    // base case
    if (n <= 2)
    {
        return 1;
    }

    // recursive case
    h[n] = Do(n - 1, h) + Do(n - 2, h);
    return h[n];

}
