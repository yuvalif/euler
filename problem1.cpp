// https://projecteuler.net/problem=1
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <algorithm>

// sum of arithmetic series given:
// first element (a1)
// number of elements (n)
// series difference (d)
unsigned aritmetic_sereies_sum(unsigned a1, unsigned n, unsigned d)
{
    // an = a1 + (n - 1)*d
    // Sn = n*(a1 + an)/2
    return n*a1 + n*(n - 1)*d/2;
}

// sum of multiples of m smaller than n
unsigned sum_of_multiples_under_n(unsigned m, unsigned n)
{
    // the sum of multiples of m under n is the sum of the arithmetic
    // series that star with m, has difference of m, and has n/m elements
    return aritmetic_sereies_sum(m, n/m, m);
}

// greatest common divisor
unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    if(x < y)
    {
       std::swap(x, y);
    }

    while(y > 0)
    {
        const auto tmp = x%y;
        x = y;
        y = tmp;
    }
    return x;
}

// least common multiplier 
unsigned long long lcm(unsigned x, unsigned y)
{
    return (x/gcd(x,y))*y;
}

unsigned Problem1()
{
    // summaries the multiples of 3 and 5 under 1000, and removes the ones counted twice
    return sum_of_multiples_under_n(3, 1000) + 
        sum_of_multiples_under_n(5, 1000) - 
        sum_of_multiples_under_n(lcm(3,5), 1000);
}

